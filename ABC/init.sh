#!/bin/bash

<<COMMENT_OUT
ARCディレクトリで実行する
./init 120
で
ARC
 |
 |-arc120
 |  |-arc120_a
 |  |    |-arc120_a.cpp
 |  |    |-test
 |  |    |  |-sample-1.in
 |  |    |  |-sample-1.out
のようなarc120以下のディレクトリを作成する.
COMMENT_OUT

number=$1  #引数から回の数字を受け取る

contest="abc"  #コンテスト名

str_number=""
if [ $number -ge 100 ]; then
  str_number="$number"
elif [ $number -ge 10 ]; then
  str_number="0$number"
else
  str_number="00$number"
fi

url_base="https://atcoder.jp/contests/${contest}${str_number}/tasks/${contest}${str_number}_"

#整数の入力のみ引き受ける
expr "$number" + 1 >&/dev/null
ret=$?
if [ $? -ge 2 ]; then
  echo "Error : Please Input Like './init.sh 45'."
  exit 1
fi

if [ $number -le 0 ]; then  #回が0以下はダメ
  echo "Error : Input Integer Only."
  exit 1
fi

temp_file_name="template.cpp"  #テンプレートファイルの名前

if [ ! -e "$temp_file_name" ]; then  #テンプレートファイルが存在しない場合
  echo "Error : ${temp_file_name} Doesn't Exist."
  exit 1
fi

do_sh="template_do.sh"  #template_do.shの名前

if [ ! -e "$do_sh" ]; then  #template_do.shが存在しない場合
  echo "Error : ${do_sh} Doesn't Exist."
  exit 1
fi

hand_sh="template_hand.sh"  #template_hand.shの名前

if [ ! -e "$hand_sh" ]; then  #template_hand.shが存在しない場合
  echo "Error : ${hand_sh} Doesn't Exist."
  exit 1
fi

sub_sh="template_sub.sh"  #template_sub.shの名前

if [ ! -e "$sub_sh" ]; then  #template_sub.shが存在しない場合
  echo "Error : ${sub_sh} Doesn't Exist."
  exit 1
fi

dir_name="${contest}${str_number}"  #作成するディレクトリの名前

if [ -e "$dir_name" ]; then  #作成するディレクトリが存在する場合
  echo "Error : ${dir_name} Is Already Exists."
  exit 1
fi   

mkdir "$dir_name"  #ディレクトリ作成

mv "$temp_file_name" "$dir_name"  #テンプレートファイルを移動
mv "$do_sh" "$dir_name"  #template_do.shを移動
mv "$hand_sh" "$dir_name"  #template_hand.shを移動
mv "$sub_sh" "$dir_name"  #template_sub.shを移動

cd "$dir_name"  #作成したディレクトリへ移動

cp "$do_sh" "do.sh"  #do.shを作成(コピーするだけ)
cp "$hand_sh" "hand.sh"  #hand.shを作成(コピーするだけ)
cp "$sub_sh" "sub.sh"  #sub.shを作成(コピーするだけ)

mv "$do_sh" ../  #template_do.shを元のディレクトリ(ARC)に戻す
mv "$hand_sh" ../  #template_hand.shを元のディレクトリ(ARC)に戻す
mv "$sub_sh" ../  #template_sub.shを元のディレクトリ(ARC)に戻す

chmod +x "do.sh"  #権限を与える
chmod +x "hand.sh"  #権限を与える
chmod +x "sub.sh"  #権限を与える

if [ $number -ge 212 ]; then  #ABC212以降(8問時代)
  for i in a b c d e f g h
    do
    name="${contest}${str_number}_${i}"  #ディレクトリの名前
    filename="${name}.cpp"  #ファイルの名前
    cp "$temp_file_name" "$filename"  #テンプレートファイルをコピーしてファイル作成
    mkdir "$name"  #arcxxx_aディレクトリを作成
    mv "$filename" "$name"  #そこへ作成したファイルを移動
    cd "$name"  #そこへ移動
    oj d "${url_base}${i}"  #テストケースを取得
    cd ../  #arcxxxディレクトリへ戻る
    done

elif [ $number -ge 126 ]; then  #ABC126以降(6問時代)
  for i in a b c d e f
    do
    name="${contest}${str_number}_${i}"  #ディレクトリの名前
    filename="${name}.cpp"  #ファイルの名前
    cp "$temp_file_name" "$filename"  #テンプレートファイルをコピーしてファイル作成
    mkdir "$name"  #arcxxx_aディレクトリを作成
    mv "$filename" "$name"  #そこへ作成したファイルを移動
    cd "$name"  #そこへ移動
    oj d "${url_base}${i}"  #テストケースを取得
    cd ../  #arcxxxディレクトリへ戻る
    done

else  ##ABC125以前(4問時代)
  for i in a b c d
    do
    name="${contest}${str_number}_${i}"  #ディレクトリの名前
    filename="${name}.cpp"  #ファイルの名前
    cp "$temp_file_name" "$filename"  #テンプレートファイルをコピーしてファイル作成
    mkdir "$name"  #arcxxx_aディレクトリを作成
    mv "$filename" "$name"  #そこへ作成したファイルを移動
    cd "$name"  #そこへ移動
    if [ $number -ge 20 ]; then  #20回以上はURLは.._a
      oj d "${url_base}${i}"  #テストケースを取得
    else  #20回未満はURLは.._1
      ar=""  #c-f時代はURLはc->a, d->b..となっている
      if [ $i = a ]; then
        ar="1"
      elif [ $i = b ]; then
        ar="2"
      elif [ $i = c ]; then
        ar="3"
      elif [ $i = d ]; then
        ar="4"
      fi
      oj d "${url_base}${ar}"  #テストケースを取得
    fi
    cd ../  #arcxxxディレクトリへ戻る
    done
fi
mv "$temp_file_name" ../  #テンプレートファイルを元のディレクトリに移動

