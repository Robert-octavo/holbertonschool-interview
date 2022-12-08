#!/usr/bin/python3
"""Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """ method that determines if all the boxes can be opened """

    # The first box boxes[0] is unlocked
    new = [0]
    for index, box in enumerate(boxes):
        # print(f"{index}: {box}")
        for value in box:
            if value != index and value < len(boxes):
                # print(value)
                new.append(value)
        # print(len(set(new)))
    return len(boxes) == len(set(new))
