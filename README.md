# FEUP-DA-PROJ2

Second project for the DA course unit at FEUP.

<!-- TODO -->

## Building

Assuming cmake is installed and setup, run `cmake -S . -B build` in this directory to generate the build system, then `cmake --build build` to build the project.

This will generate two binaries in the `build` directory, `da_proj2` and `da_proj2_no_ansi`, one that uses [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code) and one that doesn't.

Additionally, documentation will also be generated in the `docs` folder. Run `git submodule init` then `git submodule update` then build again to get the documentation website looking fancy.

## Running

Run the executable generated in the last section in the `build` directory.

The program expects the [datasets](../input/datasets) and an outputs folder to be next to the executable and tries to load the [default dataset](../input/datasets/in01_b.txt) on startup.

## Unit info

- **Name**: Desenho de Algoritmos (Algorithm Design)
- **Date**: Year 2, Semester 2, 2021/22
* **See also**: [feup-da](https://github.com/Naapperas/feup-da), [feup-da-proj1](https://github.com/Naapperas/feup-da-proj1)
- [**More info**](https://sigarra.up.pt/feup/ucurr_geral.ficha_uc_view?pv_ocorrencia_id=484424)

## Disclaimer

This repository (and all others with the name format `feup-*`) are for archival and educational purposes only.

If you don't understand some part of the code or anything else in this repo, feel free to ask (although I may not understand it myself anymore).

Keep in mind that this repo is public. If you copy any code and use it in your school projects you may be flagged for plagiarism by automated tools.
