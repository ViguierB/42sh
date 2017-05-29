#!./42sh
ls



echo ok
foreach i ( "bonjour" "ok" "aurevoir" )
  echo $i
end
foreach i ( `seq 1 10` )
  echo $i
  ls
end
