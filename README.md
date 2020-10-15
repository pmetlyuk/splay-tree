В этом репозитории рассматривается реализация сплей-дерева для следующей задачи:
<h1>Множество с запросами суммы на отрезке</h1>
Реализуйте структуру данных для хранения множества целых чисел,
поддерживающую запросы добавления, удаления, поиска, а также
суммы на отрезке. На вход в данной задаче будет дана последова-
тельность таких запросов. Чтобы гарантировать, что ваша программа
обрабатывает каждый запрос по мере поступления (то есть онлайн),
каждый запрос будет зависеть от результата выполнения одного из
предыдущих запросов. Если бы такой зависимости не было, задачу
можно было бы решить оффлайн: сначала прочитать весь вход и со-
хранить все запросы в каком-нибудь виде, а потом прочитать вход
ещё раз, параллельно отвечая на запросы.
<br>
<b>Формат входа.</b> <br>
Изначально множество пусто. Первая строка содер-
жит число запросов n. Каждая из n следующих строк содержит
запрос в одном из следующих четырёх форматов: <br>
• + i: добавить число f (i) в множество (если оно уже есть,
проигнорировать запрос);<br>
• - i: удалить число f (i) из множества (если его нет, про-
игнорировать запрос);<br>
• ? i: проверить принадлежность числа f (i) множеству;<br>
• s l r: посчитать сумму всех элементов множества, попа-
дающих в отрезок .
Функция f определяется следующим образом. Пусть s — резуль-
тат последнего запроса суммы на отрезке (если таких запросов
ещё не было, то s = 0). Тогда
  
