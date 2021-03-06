-- Дадена е базата от данни Ships, в която се съхранява информация за кораби и тяхното участие в битки по време на Втората световна война. 
-- Всеки кораб е построен по определен стереотип, определящ класа на кораба. 

-- Таблицата Classes съдържа информация за класовете кораби:
-- - class – име на клас, първичен ключ;
-- - type – тип ('bb'за бойни кораби, 'bc'за бойни крайцери); 
-- - country – държава, която строи такива кораби;
-- - numguns – брой оръдия, може да приема стойност null;
-- - bore – калибър на оръдието (в инчове), може да приема стойност null;
-- - displacement – водоизместимост (в тонове), може да приема стойност null.

-- Таблицата Ships съдържа информация за корабите:
-- - name – име на кораб, първичен ключ;
-- - class – име на клас, външен ключ към Classes.class;
-- - launched – година, в която корабът е пуснат на вода, може да приема стойност null.

-- Таблицата Battles съхранява информация за битките:
-- - name – име на битка, първичен ключ; 
-- - date – дата на провеждане.

-- Таблицата Outcomes съдържа информация за резултата от участието на даден кораб в дадена битка. 
-- Атрибутите shipи battle заедно формират първичния ключ.
-- - ship – име на кораб, външен ключ към Ships.name;
-- - battle – име на битка, външен ключ към Battles.name;
-- - result – резултат (потънал –'sunk', повреден –'damaged', победил –'ok').

-- Забележка за всички таблици: 
-- За всички атрибути, за които не е указано, че могат да приемат стойност null, да се счита, че съществува not null ограничение.

-- 1.Да се напише заявка, която извежда име на клас, годината на първата битка, в която кораб на този клас е участвал, 
-- годината на последната битка, в която кораб на този клас е участвал, и броя на всички различни битки, 
-- в които кораби на този клас са участвали, само за тези класове, започващи с буквата N. 
-- Ако за даден клас няма кораб, който да е участвал в битка, за съответните години да се върне стойност null.

SELECT c.class, MIN(b.date), MAX(b.date), COUNT(b.date)
FROM Classes c 
JOIN Ships s ON s.class = c.class
JOIN Outcomes o ON o.ship = s.name
JOIN Battles b ON b.name = o.battle
WHERE c.name LIKE 'N%'
GROUP BY c.class;

-- 2.Да се напише заявка, която да изведе имената на тези битки, за които броят на корабите от тип 'bb', 
-- участвали в тази битка, е по-голям от броя на корабите от тип 'bc', участвали в същата битка. 
-- Битки, в които не е участвал нито един кораб, да не се извеждат в резултата.
SELECT o.battle
FROM Outcomes o
JOIN Ships s ON s.name = o.ship
LEFT JOIN Classes c ON c.class = s.class
GROUP BY o.battle
HAVING SUM(c.class = 'bb') > SUM(c.class = 'bc');
