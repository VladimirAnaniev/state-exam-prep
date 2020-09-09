-- Дадена е базата от данни Movies.
-- Таблицата ​Studio​ съдържа информация зафилмови студиа:
-- - name ​​– име, първичен ключ;
-- - address​ – адрес.

-- Таблицата ​Movie​ съдържа информация за филми. 
-- Колоните ​title​ и ​year​ заедноформират първичния ключ.
-- - title​ – заглавие;
-- - year​ – година, в която филмът е заснет;
-- - length​ – дължина в минути;
-- - incolor​ – ​'Y'​ за цветен филм и ​'N'​ за черно­бял;
-- - studioname​ – име на студио, външен ключ.

-- Таблицата ​MovieStar​ съдържа информация за филмови звезди:
-- - name​ – име;
-- - address​ – адрес;
-- - gender​ – пол, ​'M'​ за мъж и ​'F'​ за жена;
-- - birthdate​ – рождена дата.

-- Таблицата ​StarsIn​ съдържа информация за участието на филмовите звезди във филмите. 
-- Трите колони заедно формират първичния ключ. 
-- Колоните ​movietitle​ и ​movieyear​ образуват външенключ към Movie.
-- - movietitle​ – заглавие на филма;
-- - movieyear​ – година на заснемане на филма;
-- - starname​ – име на филмовата звезда, външен ключ.

-- Условие 1​.​ Да се посочи заявката, която извежда имената и адресите на всички актриси от София, както и на всички филмови студиа от София. 
-- Резултатите да са сортирани по адрес.
-- б)
SELECT *
FROM (SELECT name, address
      FROM MovieStar
      WHERE gender = 'F'
      UNION
      SELECT name, address
      FROM Studio) T
WHERE T.address LIKE '%Sofia%'
ORDER BY T.address;

-- Условие 2​.​ Да се посочи заявката, която за всяко студио с най­-много три черно­бели филма извежда името му, адреса и средната дължина на филмите 
-- (без значение дали са цветни) на това студио. Студиа без филми също да се извеждат.
-- г)
SELECT name, address, AVG(length) AS avgLength
FROM Studio
LEFT JOIN Movie ON name = studioName
WHERE NAME NOT IN (SELECT studioName
                        FROM Movie
                        WHERE inColor = ‘n’
                        GROUP BY studioName
                        HAVING COUNT(*) > 3)
GROUP BY name, address;

