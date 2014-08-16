/*
 c++:汎用的な関数の作成について
 2014.08.09 tanaka hiroki
 */

/******************************************************************************
 想定:ゲームのキャラのアクションをするためのクラス
 本当ならばアクションするときにはそのキャラのクラスを引数として受け取らなくてはいけないが省略する
 あとキャラの情報を格納するのには構造体が便利だがここも省略する
 あくまで汎用的なクラスの作り方だけ見てください！
 *****************************************************************************/

#include "commonClass.h"

// コンストラクタ
commonClass()
:actType(0) // 変数actTypeを0で初期化(書き方はクラスの継承と同じ)
// 続けて何か変数を初期化したいときには","で区切る
{
}

/*
 デストラクタ省略
 */

// 初期化関数
void commonClass::actInit()
{
	// コンストラクタにはその変数型の初期値、初期化関数には自分が格納したい初期値を記述
	actType = action_type::none;
}

// アクションの格納
void commonClass::setAction(int actionType)
{
	// actTypeへのsetter
	actType = actionType;
}

// アクション
void commonClass::playAction()
{
	switch(actType)
	{
	case (action_type::none):
		// 何もしない時
		actNone();
		break;
	case (action_type::walk):
		// 歩いている時
		actWalk();
		break;
	case (action_type::run):
		// 走っている時
		actRun();
		break;
	case (action_type::jump):
		// ジャンプした時
		actJump();
		break;
	case (action_type::damage):
		// ダメージを受けた時
		actDamage();
		break;
	default:
		// 絶対にここには来ない場合でも記述したほうがbetter
		break;
	};
}

// アクションの実行関数
// 何もしない時
void commonClass::actNone()
{
	std::cout << "log:何もしていません" << std::endl;
	// 何もしないときのアニメーション処理
}

// 歩いている時
void commonClass::actWalk()
{
	std::cout << "log:歩いています" << std::endl;
	// 歩いているアニメーション処理
}

// 走っている時
void commonClass::actRun()
{
	std::cout << "log:走っています" << std::endl;
	// 走っているアニメーション処理
}

// ジャンプした時
void commonClass::actJump()
{
	std::cout << "log:ジャンプしています" << std::endl;
	// ジャンプのアニメーション処理
}

// ダメージを受けた時
void commonClass::actDamage()
{
	std::cout << "log:ダメージを受けました" << std::endl;
	// ダメージを受けたアニメーション処理
}