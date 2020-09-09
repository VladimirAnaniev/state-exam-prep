#! /bin.bash
# Текстов файл с име comproc1 съдържа зададената по­долу последователност от команди на bash за Linux. 
# Напишете вдясно какво ще бъде изведено на стандартния изход след стартиране на файла с команден ред
# bash comproc1 12 34 56
# ако на стандартния вход бъде подадена последователността от символи 5 6

var=1
for i in 4 3 2 1
do for j    
    do if [[ $i –gt $# ]]
        then  var=` expr $var \* $i`
            echo $var $j >> ff
        else continue        
        fi    
    done
done

while true
do echo $* # 12 34 56
    break
done

read  k1 k2

while cat ff | grep $k2
do set $k1 $var    
    shift 
    echo $2 
    grep $i ff    
    exit    
    echo $1
done

wc –l < ff

echo END
