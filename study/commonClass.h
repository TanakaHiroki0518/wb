/*
 c++:�ėp�I�Ȋ֐��̍쐬�ɂ���
 2014.08.09 tanaka hiroki
 */
 
/*
 ���d�Ƀw�b�_���ǂݍ��܂��ƃG���[�̌����ɂȂ邽�ߖh�~
 #ifndef �}�N��... �������̃}�N������`����Ă��Ȃ����
 #endif        ... #if,#ifdef,#ifndef�̏I��
 
 #if - #endif  = if(){}
 #ifn - #endif = if(!){}
 */
#ifndef __COMMON_CLASS__H__
#define __COMMON_CLASS__H__

#include <iostream>

/*
 enum:�񋓌^
 �����ɖ��̂����ĊǗ����邱�Ƃ��ł��郂�W���[��
 ����ɂ���ď�������̉ǐ����O���Ƃ����邵�R�[�f�B���O�~�X�����Ȃ��Ȃ�D�����
 
 ���̖��̂��珇�ɐ��l��1�������Ă����A�r���Ő��l�𖾎��I�Ɍ��߂邱�Ƃ��\�B
 */
/*
 typedef:
 �֐��ɕʖ������ĊǗ����邱�Ƃ��ł��郂�W���[��
 �������ɒP��run�Ƃ������Ă������action_type::run�Ə����Ă���ق����ǐ��������Ȃ邽�ߎg�p����
 */
typedef enum
{
	none       = 0, // �������Ȃ���
	walk,   // = 1  // ����
	run,    // = 2  // ����
	jump,   // = 3  // �W�����v����
	damage     = 99,// �_���[�W���󂯂�(�U���Ȃǂ̃A�N�V���������������ɔ����ă_���[�W�̐��l�����炷)
} action_type;

class commonClass
{
private:
	// ���̃N���X���炵���Q�Ƃł��Ȃ��A�N�Z�X�C���q
	// �ėp���W���[���̃t���O��ϐ���static�ɂ���Ƒ��̉e�����󂯂��ɒl��ێ��ł���
	static int actType;
	
	// �A�N�V�������s�֐�
	void actNone();
	void actWalk();
	void actRun();
	void actJump();
	void actDamage();
protected:
	// ���̃N���X���p�������N���X�Ƃ��̃N���X����̂ݎQ�Ɖ\�ȃA�N�Z�X�C���q
public:
	// �ǂ��̃N���X����ł��Q�Ɖ\�ȃA�N�Z�X�C���q
	
	// �R���X�g���N�^ ... �Ăяo�����FcommonClass* common = new commonClass;
	commonClass();
	// �f�X�g���N�^   ... ��{�Ăяo���Ȃ��A�N���X���g�p����Ȃ��Ȃ������Ɏ����I�ɏ���������
	~commonClass();
	
	// �������֐�
	void actInit();
	// �A�N�V�����̊i�[�p
	void setAction(int actionType);
	// �A�N�V��������
	void playAction();
};

#endif