# Convolutional Network

## How to use

### Edite file

Open main.c

```c
14 FILE* kernel_file = fopen("./kernels/sharpen.txt", "r");
28 FILE* img = fopen("./images/person.ascii.pgm", "r");
```

In line 14 you put your kernel.

In line 28 you put you image.

### Run project

To run the project you need [gcc](https://gcc.gnu.org/).

With gcc installed run:

##### In linux:

```bash
gcc main.c -o exc
./exc
```

##### In Windows

```bash
gcc main.c -o exc.exe
.\exc.exe
```

# References

[Images PGM](https://people.sc.fsu.edu/~jburkardt/data/pgma/pgma.html)

[Kernels](https://en.wikipedia.org/wiki/Kernel_(image_processing))
