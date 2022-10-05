#include <ledflashing.h>

ledflashing L1(13,500);
ledflashing L2(12,500);
void setup() {
L1.beginled();
L2.beginled();
}

void loop() {
L1.flashing(1);
L2.flashing(HIGH);
}
