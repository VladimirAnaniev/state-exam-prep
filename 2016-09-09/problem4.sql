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

-- 1. ​Да се посочи заявката, която извежда всички държави, които имат поне един кораб, участвал в битка, 
-- както и броя на потъналите кораби за всяка от държавите.
-- ??? никоя ??? може би а)

-- 2. ​Да се посочи заявката, която извежда имената на битките, които са по-мащабни (с кораби от повечедържави) от битката в Коралово море (Coral Sea).
-- А)
SELECT DISTINCT battle
FROM outcomes o1
WHERE (SELECT COUNT(DISTINCT country) 
       FROM outcomes o,ships s,classes c 
       WHERE o.ship=s.name AND s.class=c.class AND battle=o1.battle) 
        >
      (SELECT count(DISTINCT country) 
       FROM outcomes o,ships s,classes c
       WHERE o.ship=s.name AND s.class=c.class AND battle='Coral Sea')


