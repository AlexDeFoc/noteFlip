# noteFlip

A simple terminal app to flip through your notes and reveal hidden information.

## Overview

noteFlip allows you to organize your notes into decks, where each deck contains multiple cards. Every card has three sections:
- **Title**
- **Front text**
- **Back text** (initially hidden)

The key feature of noteFlip is the ability to reveal the back text of a card by using the navigation keys.

## Navigation

- **(a)**: Go to the previous card (wraps to the last card if on the first one).
- **(s)**: Reveal or hide the back of the current card.
- **(d)**: Go to the next card (wraps to the first card if on the last one).

## Usage

### 1. Creating Decks & Cards

- Create a `decks.txt` file, listing the names of your decks (one per line).
- In the app directory, create a folder called `deck`. Inside it, create a `.txt` file for each deck with the name matching those in `decks.txt`.
- Create a `card` folder. Inside it, create a folder for each deck. In each deck folder, create `.txt` files for each card (the card name will appear when browsing).

## 2. Structuring Cards

Each card is divided into three sections: title, front, and back. Below is the format to structure your cards:

```
@title
Card Title Example
@front
This is the front of the card.
Multiple lines of text are supported!
@back
This is the back of the card, hidden until revealed!
```
