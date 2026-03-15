/*
 * ============================================================
 *  RADAR BUS TRACKER — Circular Queue Backend
 *  Language  : C
 *  Structure : Circular Queue (FIFO)
 *  Capacity  : MAX_SEATS = 15 passengers per bus
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS    15
#define MAX_NAME     64
#define MAX_ID       32
#define NUM_BUSES    5

/* ── Passenger record ── */
typedef struct {
    char name[MAX_NAME];
    char passengerId[MAX_ID];
    int  seatId;
} Passenger;

/* ── Circular Queue ── */
typedef struct {
    Passenger data[MAX_SEATS];
    int  front;
    int  rear;
    int  count;
} CircularQueue;

/* ── Bus record ── */
typedef struct {
    int           busId;
    char          from[MAX_NAME];
    char          to[MAX_NAME];
    CircularQueue queue;
} Bus;

/* ════════════════════════════════════════════
   Queue operations
   ════════════════════════════════════════════ */

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear  = -1;
    q->count = 0;
}

int isFull(CircularQueue *q)  { return q->count == MAX_SEATS; }
int isEmpty(CircularQueue *q) { return q->count == 0; }

/* Enqueue — returns 1 on success, 0 if full */
int enqueue(CircularQueue *q, Passenger p) {
    if (isFull(q)) return 0;
    q->rear        = (q->rear + 1) % MAX_SEATS;
    q->data[q->rear] = p;
    q->count++;
    return 1;
}

/* Dequeue — returns 1 on success, 0 if empty */
int dequeue(CircularQueue *q, Passenger *out) {
    if (isEmpty(q)) return 0;
    *out     = q->data[q->front];
    q->front = (q->front + 1) % MAX_SEATS;
    q->count--;
    return 1;
}

/* ════════════════════════════════════════════
   Display helpers
   ════════════════════════════════════════════ */

void printPassenger(const Passenger *p) {
    printf("  Seat %-3d | %-20s | ID: %s\n",
           p->seatId, p->name, p->passengerId);
}

void showPassengers(Bus *b) {
    CircularQueue *q = &b->queue;
    printf("\n─────────────────────────────────────────\n");
    printf("  BUS %d  |  %s → %s\n", b->busId, b->from, b->to);
    printf("─────────────────────────────────────────\n");
    if (isEmpty(q)) {
        printf("  No passengers in queue.\n");
    } else {
        for (int i = 0; i < q->count; i++) {
            int idx = (q->front + i) % MAX_SEATS;
            printPassenger(&q->data[idx]);
        }
    }
    printf("─────────────────────────────────────────\n");
}

void busStatus(Bus *b) {
    CircularQueue *q = &b->queue;
    int remaining    = MAX_SEATS - q->count;
    printf("\n  Bus ID   : %d\n", b->busId);
    printf("  Route    : %s → %s\n", b->from, b->to);
    printf("  Occupied : %d / %d\n", q->count, MAX_SEATS);
    printf("  Available: %d seats\n", remaining);
    printf("  Status   : %s\n", isFull(q) ? "🔴 FULL" : (q->count >= MAX_SEATS * 0.8 ? "🟡 NEARLY FULL" : "🟢 SEATS AVAILABLE"));
}

/* ════════════════════════════════════════════
   Main interactive loop
   ════════════════════════════════════════════ */

int main(void) {
    Bus buses[NUM_BUSES] = {
        {1, "Haliyal", "Dharwad"},
        {2, "Haliyal", "Dandeli"},
        {3, "Haliyal", "Ramnagar"},
        {4, "Haliyal", "Belagavi"},
        {5, "Haliyal", "Hubli"},
    };

    /* Initialise all queues */
    for (int i = 0; i < NUM_BUSES; i++)
        initQueue(&buses[i].queue);

    int running = 1;
    while (running) {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║     RADAR BUS TRACKER — MAIN MENU   ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("  Available Buses:\n");
        for (int i = 0; i < NUM_BUSES; i++)
            printf("    [%d] Bus %d  %s → %s\n",
                   buses[i].busId, buses[i].busId,
                   buses[i].from, buses[i].to);
        printf("    [0] Exit\n");
        printf("  Select Bus ID: ");

        int choice;
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) { running = 0; break; }
        if (choice < 1 || choice > NUM_BUSES) {
            printf("  Invalid choice.\n"); continue;
        }

        Bus *b = &buses[choice - 1];
        int dashRunning = 1;

        while (dashRunning) {
            printf("\n┌─────────────────────────────┐\n");
            printf("│  BUS %d DASHBOARD            │\n", b->busId);
            printf("│  Route: %s → %-10s    │\n", b->from, b->to);
            printf("│  Passengers: %2d / %2d         │\n", b->queue.count, MAX_SEATS);
            printf("├─────────────────────────────┤\n");
            printf("│  [1] Add Passenger           │\n");
            printf("│  [2] Remove Passenger        │\n");
            printf("│  [3] Show Passengers         │\n");
            printf("│  [4] Bus Status              │\n");
            printf("│  [0] Back to Main Menu       │\n");
            printf("└─────────────────────────────┘\n");
            printf("  Action: ");

            int action;
            if (scanf("%d", &action) != 1) break;

            switch (action) {
                case 0:
                    dashRunning = 0;
                    break;

                case 1: { /* Add Passenger */
                    if (isFull(&b->queue)) {
                        printf("  ⚠ Bus is FULL. Cannot add passenger.\n");
                        break;
                    }
                    Passenger p;
                    printf("  Passenger Name : ");
                    scanf(" %63[^\n]", p.name);
                    printf("  Passenger ID   : ");
                    scanf(" %31[^\n]", p.passengerId);
                    printf("  Seat ID        : ");
                    scanf("%d", &p.seatId);
                    if (enqueue(&b->queue, p))
                        printf("  ✓ %s added to Bus %d (Seat %d)\n",
                               p.name, b->busId, p.seatId);
                    break;
                }

                case 2: { /* Remove Passenger (FIFO) */
                    Passenger removed;
                    if (dequeue(&b->queue, &removed))
                        printf("  ✓ Removed: %s (Seat %d)\n",
                               removed.name, removed.seatId);
                    else
                        printf("  ⚠ Queue is empty.\n");
                    break;
                }

                case 3: /* Show Passengers */
                    showPassengers(b);
                    break;

                case 4: /* Bus Status */
                    busStatus(b);
                    break;

                default:
                    printf("  Invalid action.\n");
            }
        }
    }

    printf("\n  Thank you for using Radar Bus Tracker!\n\n");
    return 0;
}
