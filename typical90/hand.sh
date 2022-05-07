#!/bin/bash

<<COMMENT_OUT
問題1を解く時
typical90ディレクトリ上で ./hand.sh 1
./hand.sh 1 uu
で実行. uuの部分はなんでも良い.
COMMENT_OUT

i=$1  #1, 2などの問題番号
num=${i}

full_cr_dir_name=`pwd *`  #カレントディレクトリの絶対パス
#カレントディレクトリの名前
cr_dir_name=`echo ${full_cr_dir_name} | awk -F "/" '{ print $NF }'`
sub_dir_name="${cr_dir_name}_${num}"  #テストする問題のディレクトリ名前

if [ ! -e "$sub_dir_name" ]; then  #テストする問題のディレクトリが見つからない場合
  echo "Error : ${sub_dir_name} Doesn't Exist."
  exit 1
fi

cd "$sub_dir_name"
file_name="${sub_dir_name}.cpp"

if [ ! -e "$file_name" ]; then  #テストするc++ソースが存在しない場合
  echo "Error : ${file_name} Doesn't Exist."
  cd ../
  exit 1
fi

if [ $# = 2 ]; then #テストするc++ソースがboostライブラリを使用している
  g++ "$file_name" -I /usr/local/include
elif [ $# = 1 ]; then
  g++ "$file_name"
fi

./a.out


