To compile the code:

You need ncurses library installed, as well as cmake version 3.16 or higher
```
git clone https://github.com/somesoo/Tetris.git
```
enter your project folder, and create build dir using 
```
cd/Tetris
mkdir -p out/build/
cd out/build/
```
in directory ~/out/build/ use these commands to compile your program using cmake:
```
cmake -S ../../ -B .
make
./TETRIS
```

**Basic player movement:**
```
a - go left
d - go right
x - rotate
space - rotate
```
