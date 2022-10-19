# push_swap

Цель проекта
--
Отсортировать стек целых чисел по возрастанию, используя второй стек и некоторые команды.

Почему push_swap важен?
--
Данный проект дает знакомит нас со стеком (список) - тип данных, представляющий собой список, организованный по принципу "Последним пришел - первым вышел". В данном проекте используется динамическое программирование: определяем необходимое кол-во шагов для каждого элемента стека, чтобы поставить его на нужное место в другой стек - и так каждый раз после перемещения.

Обязательная часть
--
- На вход поступает последовательность целых чисел. Задача - отсортировать их по возрастанию.
- Изменять положение элементов в списке можем используя следующие команды:
 - sa, sb: Поменять местами два верхних элемента стека
 - ra, rb: Переместить верхний элемент стека в конец данного стека
 - rra, rrb: Переместить нижний элемент стека в начало данного стека
 - pa, pb: Переместить верхний элемент одного стека в начало другого
- Вывод программы представляет собой список команд

Бонусная часть
--
- Задача - написать чекер - программу, проверяющую список команд для последовательности целых чисел, действительно ли данная комбинация команд отсортирует стек.
- Команды поступают в стандартный ввод, после запуска программы с последовательностью чисел. Концом команд используется EOF.


Более подробно в задании (находится в этом репозитории - en.subject.pdf)
