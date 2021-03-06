-- Дадена е базата от данни Movies, в която се съхранява информация за филми, 
-- филмови студии, които ги произвеждат, продуцентите на филмите, 
-- както и актьорите, които участват в тях.

-- Таблицата Movie съдържа информация за филми. 
-- Атрибутите title и year заедно формират първичния ключ.
--   title – заглавие;
--   year – година, в която е заснет филмът;
--   length – дължина в минути;
--   incolor – 'Y' за цветен филм и 'N' за чернобял;
--   studioname – име на студио, външен ключ към Studio.
--   name;
--   producerc# - номер на сертификатна продуцента, външен ключ към MovieExec.
--   cert#.

-- Таблицата Studio съдържа информация за филмови студиа:
--   name – име, първичен ключ;
--   address – адрес;
--   presc#-номер на сертификатна президента на студиото.

-- Таблицата MovieStar съдържа информация за филмови звезди:
--   name – име, първичен ключ;
--   address – адрес;
--   gender – пол, 'M' за мъж и 'F' за жена;
--   birthdate – рождена дата.

-- Таблицата StarsIn съдържа информация за участието на филмовите звезди във филмите. 
-- Трите атрибута заедно формират първичния ключ. 
-- Атрибутите movietitle и movieyear образуват външен ключ към Movie.
--   movietitle – заглавие на филма;
--   movieyear – година на заснемане на филма;
--   starname – име на филмовата звезда, външен ключ към MovieStar. 
--   name.

-- Таблицата MovieExec съдържа информация за продуцентите на филми.
--   cert# – номер на сертификат, първичен ключ;
--   name – име;
--   address – адрес;
--   networth – нетни активи;

-- Забележка за всички таблици: 
-- Всички атрибути, които не участват във формирането на първичен ключ, могат да приемат nullстойност.

--------------------------------------------------------------------
--------------------------------------------------------------------
--------------------------------------------------------------------

-- 1. Попълнете липсващите части, обозначени с ______ така, 
-- че заявката да изведе за всяко студио името на студиото, 
-- заглавието и годината на филма,излязъл последно на екран за това студио.
SELECT studioname, title, year 
FROM movie m WHERE year = (SELECT MAX(year) FROM movie WHERE studioname = m.studioname);

-- 2. Попълнете липсващитечасти, обозначени с ______ така, 
-- че заявката да изведе име на продуцент и обща дължина на продуцираните от него филми, 
-- за тези продуценти, които имат поне един филм преди 1980 г.
SELECT name, SUM(length)
FROM movieexec 
JOIN movie ON producerc# = cert#
GROUP BY name
HAVING MIN(year) < 1980;

-- 3. Попълнете липсващите части, обозначени с ______ така, 
-- че заявката да изведе име на актьорите, участвали във филми на продуценти с най-големи нетни активи, 
-- както и заглавие на филмите, в които са участвали, име на продуцент и нетни активи.
SELECT starname, title, name, networth
FROM starsin 
JOIN movie ON movietitle = title AND movieyear = year
JOIN (SELECT cert#, networth, name
      FROM movieexec 
      WHERE networth = (SELECT MAX(networth) FROM movieexec)) t ON t.cert# = producerc#;

-- 4. Заградете буквата назаявката, която извежда името на продуцента, 
-- заглавието и годината на всички филми, продуцирани от продуцента на филма ‘Interstellar’.
-- Б)
SELECT t.name, title, year
FROM movie m 
JOIN (SELECT name, cert#
      FROM movieexec
      WHERE EXISTS (SELECT producerc#
                    FROM movie
                    WHERE title='Interstellar')) t ON m.producerc#=t.cert#;
