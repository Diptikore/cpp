<html>
<div>
 <div>
 <h2>
        Ray
    </h2>
 <p><b> 
        Решение задачи о нахождении для заданной окружности и луча точки пересечения на плоскости  
 </b></p>
 <p>
       В качестве исходных данных программа использует вводимые пользователем координаты центра и радиус окружности, точку начала и любую другую точку луча.
    </p>
 <p>
        Алгоритм крайне прост.
        Запишем параметрическое уравнение прямой, проходящей через две заданные точки. Подставим x и y, выраженные через t, в уравнение окружности. Получится квадратное уравнение, решения которого - пересечения прямой и окружности. 
 </p>
<ul><b>Содержание:</b>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/Ray/Lab_1/main.cpp">Main.cpp</a> - основные алгоритмы</li>
    </ul>
    </div>

 <div>
    <h2>
        Rectangle search
    </h2>
    <br>
    <p><b> 
        Решение задачи о нахождении для заданного набора точек в плоскости произвольно ориентированный прямоугольник, содержащий все точки
    </b></p>
  <ul> <b>Содержание:</b>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/RectangleSearch/Lab_4/Main.cpp">Main.cpp</a> - интерфейс программы</li>
       <li><a href="https://github.com/mikenmsl/cpp/blob/master/RectangleSearch/Lab_4/WorkPoint.cpp">WorkPoint.cpp</a> - работа с координатами точек, работа с файлами</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/RectangleSearch/Lab_4/Inspection.cpp">Inspection.cpp</a> - проверка корректного ввода координат, имени и пути файла</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/RectangleSearch/Lab_4/ModuleTest.cpp">ModuleTest.cpp</a> - модульные тесты</li>
    </ul>

 <ul> <b>Опции:</b>
        <li>Проверка корректного ввода координат, имени и пути файла</li>
        <li>Модульные тесты</li>
        <li>Сохранение исходных данных</li>
        <li>Сохранение полученного результата</li>
        <li>2 решения: с использованием STL и без</li>
        <li>Чтение данных из файлов</li>
    </ul>
    <p>
        В качестве исходных данных программа использует координаты (x;y) минимум трех не лежащих на одной прямой точек. <br>
        Программа использует алгоритм Джарвиса по поиску наименьшей выпуклой оболочки и отбрасываем все ненужные (лишние) точки.
    </p>
    <a href="#rectangle-search">ссылка на описание алгоритма</a>
    </div>

<div>
<h2>
        Ellips
    </h2>

 <p><b> 
        Решение задачи о нахождении для заданного набора точек в плоскости эллипс с минимальной  суммой длин полуосей, содержащий все указанные точки. 
    </b></p>
     <ul> <b>Содержание:</b>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/ellips/Project_09_05/Source.cpp">Source.cpp</a> - интерфейс программы</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/ellips/Project_09_05/WorkPoint.cpp">WorkPoint.cpp</a> - работа с координатами точек, работа с файлами</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/ellips/Project_09_05/Inspection.cpp">Inspection.cpp</a> - проверка корректного ввода координат, имени и пути файла</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/ellips/Project_09_05/ModuleTest.cpp">ModuleTest.cpp</a> - модульные тесты</li>
    </ul>
 <ul> <b>Опции:</b>
        <li>Проверка корректного ввода координат, имени и пути файла</li>
        <li>Модульные тесты</li>
        <li>Сохранение исходных данных</li>
        <li>Сохранение полученного результата</li>
        <li>2 решения: с использованием STL и без</li>
        <li>Чтение данных из файлов</li>
    </ul>
 <p>
        В качестве исходных данных программа использует координаты (x;y) минимум трех не лежащих на одной прямой точек. <br>
    </p>
    <a href="#elips">ссылка на описание алгоритма</a>
    </div>

<div>
 <h2>
        Search Rows
    </h2>
<p><b> 
        Решение задачи о нахождении наибольшей общей подстроки в двух строках. 
    </b></p>
 <ul> <b>Содержание:</b>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/SearchRows/Lab_3/Main.cpp">Main.cpp</a> - интерфейс программы</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/SearchRows/Lab_3/WorkFile.cpp">WorkFile.cpp</a> -  работа с файлами, чтение и сохранение данных</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/SearchRows/Lab_3/Inspection.cpp">Inspection.cpp</a> - проверка корректного ввода данных</li>
        <li><a href="https://github.com/mikenmsl/cpp/blob/master/SearchRows/Lab_3/ModuleTest.cpp">ModuleTest.cpp</a> - модульные тесты</li>
    </ul>

 <ul> <b>Опции:</b>
        <li>Проверка корректного ввода строк, имени и пути файла</li>
        <li>Модульные тесты</li>
        <li>Сохранение исходных данных</li>
        <li>Сохранение полученного результата</li>
        <li>Чтение данных из файлов</li>
    </ul>
 <p>
        Алгоритм крайне прост. 
        Выбираем первый элемент первого текста и перебирая элементы второго текста ищем схожий. Если схожий находится, сравниваем следующие элементы текстов.
 Если последовательность наибольшая, запоминаем индексы начала подстроки в обоих текстах.
 <br>
    </p>
    </div>








<div id="rectangle-search">
<h3>Rectangle searcht</h3>
<p> Используем алгоритм Джарвиса по поиску наименьшей выпуклой оболочки и отбрасываем все ненужные (лишние) точки. 
Берется самая левая точка. <br> Следующей точкой  p_{2}берём такую точку, которая имеет наименьший положительный полярный угол относительно точки  p_{1} как начала координат. После этого для каждой точки p_{i} (2'<'i'<'=|P|) против часовой стрелки ищется такая точка p_{i+1}, путём нахождения за  O(n) среди оставшихся точек (+ самая левая нижняя), в которой будет образовываться наибольший угол между прямыми 
p_{i-1} p_{i} и  p_{i} p_{i+1}. <br>Она и будет следующей вершиной выпуклой оболочки. Сам угол при этом не ищется, а ищется только его косинус через скалярное произведение между лучами p_{i-1} p_{i} и p_{i} p'_{i+1}, где  p_{i} — последний найденный минимум, p_{i-1}} — предыдущий минимум, а p'_{i+1} — претендент на следующий минимум. <br>Новым минимумом будет та точка, в которой косинус будет принимать наименьшее значение (чем меньше косинус, тем больше его угол). 
Дальше точки выпуклой оболочки передаются в функцию поиска наименьшего прямоугольника. Нам известно, что наименьший прямоугольник для заданных точек будет лежать на наибольшей стороне выпуклой оболочки. <br>
Находим угол наклона между наибольшей стороной выпуклой оболочки и поворачиваем все точки относительно центра этой стороны по формуле: 
X = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);
Y = y0 + (y - y0) * cos(a) + (x - x0) * sin(a);
где, (x0, y0) — центр, точка вокруг которой нужно вращать
Тем самым мы сделали отрезок параллельно оси ОХ<br>

Далее мы находим самую левую, нижнюю, правую и верхнюю точку и соответственно строим точки прямоугольника. Далее поворачиваем их назад на (360-а) градусов.
Округляем полученные точки.
</p>
</div>

<div id="elips">
    <h3>Elips</h3>
    <p>
        Все расчеты мы сводим к формуле эллипса <img src="https://image.ibb.co/g88v9z/image.png" alt="image" border="0">
Сперва находим две точки, расстояние между которыми самое большое. 
Вычисляем середину отрезка между ними, эта точка является новым началом наших координат.
Чтобы сместить старую точку начала координат (0;0) вычитаем из всех точек соответствующие координаты новой точки начала координат.
Находим угол наклона наибольшего отрезка к оси OX через угловой коэффициент по формуле 
<img src="https://thumb.ibb.co/gDdHNK/image.png" alt="image" border="0">

Далее поворачиваем наши точки вокруг нового центра на угол наклона к оси по формулам 
X = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);
Y = y0 + (y - y0) * cos(a) + (x - x0) * sin(a);
где, (x0, y0) — центр, точка вокруг которой нужно вращать
Тем самым мы сделали отрезок параллельно оси ОХ
Далее методом подстановки мы ищем оптимальные значения a и b, чтобы выполнялась формула эллипса 
<img src="https://image.ibb.co/g88v9z/image.png" alt="image" border="0">
    </p>
</div>







</html>
