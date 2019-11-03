# Formal_languages_3sem

Мажейка Михаил, группа 824, Practice_1, вариант 15.

Дано регулярное выражение в обратной польской записи и слово u ∈ {a, b, c}* Найти длину самого длинного префикса u, явля-
ющегося также префиксом некоторого слова в L.

Идея решения:
Создадим структуру Reg_exp, которая содержит всю необходимую информацию для решения задачи. Для каждого
регулярного выражения и для каждого подслова u нам нужно знать: является ли подслово u некоторым префиксом слова из регулярки и 
является ли подслово u некоторым словом из регулярки.
Тогда с помощью обратной польской записи мы сможем на стеке хранить структуру Req_exp, которая как раз и описывает нам регулярку.
Перегрузим соответсвующие операторы структуры по логичным правилам.

Таким образом мы перевели условие задачи на работу с нужной нам информацией для регулки и операциями между ними.

Ниже тесты, которые покрывают 90% написанного кода программы.
Code coverage я не сделал, если это необходимое условие, то обязательно этим займусь.


