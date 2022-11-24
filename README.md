# cryptography_lab4
## Description
Реализовать двухступенчатый генератор псевдослучайных чисел. Первая ступень – конгруэнтный генератор с модулем 216. Она предна-значена для генерации стартовых значений для второй ступени. Вто-рая ступень – 17-разрядный линейный сдвиговый регистр с обратной связью. Регистр на основе значения, полученного из первой ступени (старший разряд считаем равным 0), генерирует фрагмент гаммы шифра длиной 128 бит, а затем передает управление первой ступени, и процесс циклически повторяется. Реализовать гаммирование текста, состоящего из символов 64-символьной кодовой таблицы
## Building
- Download [CMake](https://cmake.org/download/) version ***3.25.0*** ***required***
- Do this in your terminal
	- ```git clone https://github.com/kr1v4/cryptography_lab4.git``` or download Latest version in [Releases](https://github.com/kr1v4/cryptography_lab4/releases) page
	- ```cd cryptography_lab4``` 
	- ```mkdir build && cd build``` 
	- ```cmake ..```
	- ```cmake --build . --config Release```
- Enjoy!
