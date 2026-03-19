# Ejercicios sobre el uso de Listas y Pilas

## Project Overview
A C-based laboratory assignment focused on implementing List and Stack (TDA) data structure operations.

## Tech Stack
- **Language**: C (compiled with gcc 14.3)
- **Build**: `gcc -g test.c -Wall -Werror -o a.out`
- **Test runner**: `test.sh` (bash script)

## Project Structure
- `exercises.c` — Student implementation file (edit this to complete exercises)
- `test.c` — Test suite (do not edit)
- `arraylist.c` / `arraylist.h` — ArrayList TDA implementation
- `stack.h` — Stack TDA (wrapper around ArrayList)
- `test.sh` — Compilation, testing, logging, and optional GitHub push script
- `log` — Auto-updated test result log

## Workflow
- **Start application**: runs `bash test.sh` (console output)
  - Compiles `test.c` with gcc
  - Runs the compiled binary and shows test results
  - Optionally pushes progress to GitHub

## Exercises to Implement (in exercises.c)
1. `crea_lista()` — Create a list with integers 1–10
2. `sumaLista()` — Sum elements of an integer list
3. `eliminaElementos()` — Remove all occurrences of a value from a list
4. `copia_pila()` — Copy a stack preserving order
5. `parentesisBalanceados()` — Check balanced parentheses/brackets/braces using a stack
