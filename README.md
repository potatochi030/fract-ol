*This project has been created as part of the 42 curriculum by aoqdeh.*

# Fractol

## Description

Fractol is a graphical project focused on rendering and exploring mathematical
fractals using computer graphics.

The program generates fractals such as the Mandelbrot and Julia sets by
performing complex number calculations and displaying the results in a window.
It allows user interaction through zooming, panning, and modifying parameters
in real time.

This project emphasizes:
- Mathematical concepts and complex numbers
- Graphics programming
- Event handling and user input
- Performance optimization and precision

## Instructions

### Compilation

The project is compiled using the provided Makefile. Ensure that the required
graphics library is installed, then compile the program using:

```bash
make
```
This will generate the fractol executable.

### Execution

Run the program by specifying the fractal to display:

```bash
./fractol mandelbrot
```

For fractals that require parameters, such as Julia sets, run:

```bash
./fractol julia 0.285 0.01
```
### Controls

Mouse wheel: Zoom in and out of the fractal

ESC key or window close button (X): Exit the program

# Resources
## References

- [Minilibx Manual](https://harm-smits.github.io/42docs/libs/minilibx)

- [fract-ol: creating graphically beautiful fractals ~ Léo Gaudin](https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5)

- [fract-ol — render beautiful sets ~ Braulio Santos](https://medium.com/@by1jorgesantos/fract-ol-render-beautiful-sets-0699a378b953)

## AI Usage

AI tools were used to assist with testing and to explain certain concepts related
to the project. AI assistance was limited to clarification and validation purposes.

All code was written without the use of AI.