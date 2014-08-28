/*
 c++:汎用的な関数の作成について
 2014.08.09 tanaka hiroki
 */
 
/*
 多重にヘッダが読み込まれるとエラーの原因になるため防止
 #ifndef マクロ... もしこのマクロが定義されていなければ
 #endif        ... #if,#ifdef,#ifndefの終了
 
 #if - #endif  = if(){}
 #ifn - #endif = if(!){}
 */
#ifndef __COMMON_CLASS__H__
#define __COMMON_CLASS__H__

#include <iostream>

/*
 enum:列挙型
 数字に名称をつけて管理することができるモジュール
 これによって条件分岐の可読性がグンとあがるしコーディングミスも少なくなる優れもの
 
 頭の名称から順に数値が1ずつ増えていく、途中で数値を明示的に決めることも可能。
 */
/*
 typedef:
 関数に別名をつけて管理することができるモジュール
 条件式に単にrunとか書いてあるよりもaction_type::runと書いてあるほうが可読性が高くなるため使用した
 */
typedef enum
{
	none       = 0, // 何もしない時
	walk,   // = 1  // 歩く
	run,    // = 2  // 走る
	jump,   // = 3  // ジャンプする
	damage     = 99,// ダメージを受けた(攻撃などのアクションが増えた時に備えてダメージの数値をずらす)
} action_type;

class commonClass
{
private:
	// このクラスからしか参照できないアクセス修飾子
	// 汎用モジュールのフラグや変数はstaticにすると他の影響を受けずに値を保持できる
	static int actType;
	
	// アクション実行関数
	void actNone();
	void actWalk();
	void actRun();
	void actJump();
	void actDamage();
protected:
	// このクラスを継承したクラスとこのクラスからのみ参照可能なアクセス修飾子
public:
	// どこのクラスからでも参照可能なアクセス修飾子
	
	// コンストラクタ ... 呼び出し方：commonClass* common = new commonClass;
	commonClass();
	// デストラクタ   ... 基本呼び出さない、クラスが使用されなくなった時に自動的に処理をする
	~commonClass();
	
	// 初期化関数
	void actInit();
	// アクションの格納用
	void setAction(int actionType);
	// アクションする
	void playAction();
};

#endif