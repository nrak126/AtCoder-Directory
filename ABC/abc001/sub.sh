#!/bin/bash

<<COMMENT_OUT
./sub.sh a
これはarcxxxから行う. arcxxx_aディレクトリに遷移してはいけない.
提出を行う.
COMMENT_OUT

problem=$1  #a, bなどの問題番号
full_cr_dir_name=`pwd *`  #カレントディレクトリの絶対パス
#カレントディレクトリの名前
cr_dir_name=`echo ${full_cr_dir_name} | awk -F "/" '{ print $NF }'`
sub_dir_name="${cr_dir_name}_${problem}"  #テストする問題のディレクトリ名前

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

oj s "$file_name"
cd ../
