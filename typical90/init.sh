#!/bin/bash

url_base="https://atcoder.jp/contests/typical90/tasks/typical90_"

temp_file_name="template.cpp"  #テンプレートファイルの名前

if [ ! -e "$temp_file_name" ]; then  #テンプレートファイルが存在しない場合
  echo "Error : ${temp_file_name} Doesn't Exist."
  exit 1
fi

do_sh="do.sh"  #do.shの名前

if [ ! -e "$do_sh" ]; then  #do.shが存在しない場合
  echo "Error : ${do_sh} Doesn't Exist."
  exit 1
fi

hand_sh="hand.sh"  #hand.shの名前

if [ ! -e "$hand_sh" ]; then  #hand.shが存在しない場合
  echo "Error : ${hand_sh} Doesn't Exist."
  exit 1
fi

sub_sh="sub.sh"  #sub.shの名前

if [ ! -e "$sub_sh" ]; then  #sub.shが存在しない場合
  echo "Error : ${sub_sh} Doesn't Exist."
  exit 1
fi

for i in {1..90};
  do
  num="${i}"
  chr=""
  str=""
  declare -a array=("a" "b" "c" "d" "e" "f" "g" "h" "i" "j" "k" "l" "m" "n" "o" "p" "q" "r" "s" "t" "u" "v" "w" "x" "y" "z")
  if [ $i -ge 79 ]; then
    chr="${array[$((i-79))]}"
    str="c${chr}"
  elif [ $i -ge 53 ]; then
    chr="${array[$((i-53))]}"
    str="b${chr}"
  elif [ $i -ge 27 ]; then
    chr="${array[$((i-27))]}"
    str="a${chr}"
  else
    chr="${array[$((i-1))]}"
    str="${chr}"
  fi
  echo "${array[$((i-1))]}"
  echo "${str}"
  dir_name="typical90_${num}"
  url="${url_base}${str}"
  filename="${dir_name}.cpp"

  mkdir "$dir_name"
  mv "$temp_file_name" "$dir_name"  #テンプレートファイルを移動
  cd "$dir_name"
  cp "$temp_file_name" "$filename"  #テンプレートファイルをコピーしてファイル作成
  oj d "$url"  #テストケースを取得
  mv "$temp_file_name" ../  #テンプレートファイルを元のディレクトリに移動
  cd ../ 
  done

chmod +x "do.sh"  #権限を与える
chmod +x "hand.sh"  #権限を与える
chmod +x "sub.sh"  #権限を与える

