#!/usr/bin/python3

def canUnlockAll(boxes):
    """unlock funtion

    Args:
        boxes: list of lists of integer that represent the number of a key

    Returns:
        True if all unlocked
    """

    n = len(boxes)
    unlocked = [False] * n
    # box 0 ouverte
    unlocked[0] = True
    # keys 0 initialisée
    keys = [0]

    while keys:
        # current_box sera 0 au premier tour
        current_box = keys.pop()
        for key in boxes[current_box]:
            if not unlocked[key]:
                # stockage de l info
                unlocked[key] = True
                # ajout d une nouvelle clé
                keys.append(key)
    # quand il y a plus de clés: on retoune le résultat d'un ET logique sur la liste unlocked
    return all(unlocked)