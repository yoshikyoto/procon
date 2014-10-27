# プロコン用C++テンプレ

## using namespace std;
プロコン以外ではやってはいけない


## define FOR(i, n)


## iostream 最適化
* `cin.tie(0);' で cin と cout の結びつきを解除。
  * cin は呼び出されるたびに cout をフラッシュしているらしい。
* `ios::sync_with_stdio(false);' で stdio との同期を解除
* stdio では endl ではなく \n を使ったほうが早くなるらしい。



## TODO
* プロジェクト名「aoj」はなんとかする。