В этом репозитории рассматривается реализация сплей-дерева для следующей задачи:
<h1>Множество с запросами суммы на отрезке</h1>
Реализуйте структуру данных для хранения множества целых чисел,
поддерживающую запросы добавления, удаления, поиска, а также
суммы на отрезке. На вход в данной задаче будет дана последовательность таких запросов. 
Чтобы гарантировать, что ваша программа обрабатывает каждый запрос по мере поступления (то есть онлайн),
каждый запрос будет зависеть от результата выполнения одного из предыдущих запросов. 
Если бы такой зависимости не было, задачу можно было бы решить оффлайн: 
сначала прочитать весь вход и сохранить все запросы в каком-нибудь виде, 
а потом прочитать вход ещё раз, параллельно отвечая на запросы.
<br>
<b>Формат входа.</b> <br>
Изначально множество пусто. Первая строка содержит число запросов n. 
Каждая из n следующих строк содержит запрос в одном из следующих четырёх форматов: <br>
• <nobr>+ _i</nobr>: добавить число <nobr>f(i) </nobr> в множество (если оно уже есть,
проигнорировать запрос);<br>
• <nobr>- _i</nobr>: удалить число <nobr>f(i) </nobr> из множества (если его нет, про-
игнорировать запрос);<br>
• <nobr>? _i</nobr>: проверить принадлежность числа <nobr>f(i) </nobr> множеству;<br>
• <nobr>_s _l _r</nobr>: посчитать сумму всех элементов множества, попадающих в отрезок .
Функция <nobr>f</nobr> определяется следующим образом. Пусть <nobr>s</nobr> — результат 
последнего запроса суммы на отрезке (если таких запросовещё не было, то <nobr>s = 0 </nobr>). 
Тогда f(x) = x + s mod 1000000001
<b>Формат выхода</b>. Для каждого запроса типа ? i выведите «Found»
или «Not found». Для каждого запроса суммы выведите сумму
всех элементов множества, попадающих в отрезок[f(l), f(r)].
