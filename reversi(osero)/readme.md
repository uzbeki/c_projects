# Reversi Game
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)


# ORIGIN 
Reversi is an ancient game whose origin is uncertain. The oldest references about similar games go back to late in the 19th century; those games had different names and their boards had different size or shape. In 1870 appeared a similar game using a cross shape board. Subsequently appeared another game played on a 8x8 square shape board.

# DESCRIPTION
Two players take part in this game; they need a board with 64 squares distributed in 8 rows and 8 columns, and 64 similar of two colours (normally black and white): the obverse one colour and the reversi in the other colour.

# OBJECTIVE
The objective for each of the players is to finish the game with more pieces on the board in his own colour than the opponent.

## How the game goes on

# START OF THE GAME #
Before starting players decide which colour will use each of them. Next 4 pieces have to be placed in the central squares of the board, so that each pair of pieces of the same colour form a diagonal between them. The player with black pieces moves first; one only move is made every turn.
# MOVES
A move consists in placing from outside one piece on the board. Placed pieces can never be moved to another square later in the game. The incorporation of the pieces must be made according to the following rules: 
* The incorported piece must outflank one or more of the opponent placed pieces.
* To outflank means that a single piece or one straight row (vertical, horizontal or diagonal) of pieces of the opponent is in both sides next to own pieces, with no empty squares between all those pieces.
* The player who makes the move turns the outflanked pieces over, becoming all of them in own pieces.
* If there is more than one outflanked row, all the involved pieces in those rows have to be flipped.
* If it´s not possible to make this kind of move, turn is forfeited and the opponent repeats another move.
# FINAL
The game is over when all the squares of the board are taken or none of the players can move. In any case the winner is the player who has more pieces on the board. The game ends in a draw when both players have the same number of pieces on the board.

> This game is my very first try in learning C. Please feel free to copy, learn and collaborate.
> You can reach me out at [bekhruz.com](https://bekhruz.com "My personal website").