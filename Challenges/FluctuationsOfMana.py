n = int(input())
k = list(map(int, input().split()))
current_mana = 0
min_mana_needed = 0
for change in k:
    current_mana += change
    if current_mana < 0:
        min_mana_needed = min(min_mana_needed, current_mana)
min_mana_needed = abs(min_mana_needed)
print(min_mana_needed)