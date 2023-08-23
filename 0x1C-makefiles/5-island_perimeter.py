#!/usr/bin/python3
"""
    Functs that return the perimetr\
    of the island describ in a grid
"""


def island_perimeter(grid):
    """" Returning the perimetr of the\
    island describ in a grid"""
    if not len(grid):
        return 0

    perimeter = 0
    for v, g_cell in enumerate(grid):
        for m, cell in enumerate(g_cell):
            if cell:
                perimeter += 4
                if v != 0 and grid[v - 1][m] == 1:
                    perimeter -= 2
                if m + 1 != len(g_cell) and g_cell[m + 1] == 1:
                    perimeter -= 2

    return perimeter
