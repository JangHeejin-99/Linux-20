#!/bin/bash

i=0
s=0 # 합을 담을 변수

for i in $@ # $@ = 모든 포지션 인자 
do
	s=$((s+i))
	# 모든 포지션 인자를 합한다. 
	# 수치 연산자 사용시 let또는 (())를 사용해야함 
done

echo $s # 합 출력

exit 0

