#!/usr/bin/python3
"""Solves the n queens problem"""

import sys


def nqueens(n):
    """Solves the n queens problem"""
    if n < 4:
        print('N must be at least 4')
        sys.exit(1)
    if type(n) is not int:
        print('N must be a number')
        sys.exit(1)
    board = [[0 for i in range(n)] for j in range(n)]
    solutions = []
    solve(board, 0, solutions)
    for solution in solutions:
        print(solution)


def solve(board, col, solutions):
    """Solves the n queens problem"""
    if col >= len(board):
        solutions.append(board)
        return True
    res = False
    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = 1
            res = solve(board, col + 1, solutions) or res
            board[i][col] = 0
    return res


def is_safe(board, row, col):
    """Checks if a queen can be placed on board[row][col]"""
    for i in range(col):
        if board[row][i] == 1:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < len(board):
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1
    return True


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)
    nqueens(n)
