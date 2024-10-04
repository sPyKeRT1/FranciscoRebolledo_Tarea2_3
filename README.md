# AlgoReportTemplate

## Descripción

Este repositorio contiene una plantilla en **LaTeX** diseñada específicamente para la creación de informes y reportes en la asignatura **Algoritmos y Complejidad** del Departamento de Informática de la **Universidad Técnica Federico Santa María (UTFSM)**. La plantilla está estructurada para facilitar la redacción de tareas, reportes de laboratorio y proyectos relacionados con el análisis de algoritmos.

### 

- Escriba sus datos en `author.tex`.
- `preamble.tex` y `tarea_main.tex` NO debe ser modificados.
- La estructura de archivos de `sections/` No debe ser modificada. Sólo agregue texto a los archivos existentes.
- `references.bib` contiene las referencias bibliográficas. Agregue las suyas.
- `tikz/` contiene archivos `.tex` con gráficos generados con `TikZ`. Puede agregar más archivos `.tex` con gráficos.
- `tarea_main.pdf` es el archivo de salida generado por `pdflatex`.
- `images/` contiene imágenes. Puede agregar más imágenes.

```bash
pablo@asus:~/Documents/AlgoReportTemplate$ tree
.
├── author.tex
├── condiciones.tex
├── preamble.tex
├── README.md
├── references.bib
├── sections
│   ├── abstract.tex
│   ├── appendix1.tex
│   ├── conclusions.tex
│   ├── design_analysis_brute_force.tex
│   ├── design_analysis_dynamic_programming.tex
│   ├── design_analysis.tex
│   ├── experiment_dataset.tex
│   ├── experiment_intro.tex
│   ├── experiment_results.tex
│   ├── implementations.tex
│   └── introduction.tex
├── tarea_main.pdf
├── tarea_main.tex
└── tikz
    └── plot1.tex

3 directories, 19 files

```
