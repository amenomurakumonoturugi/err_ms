#include <Windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <filesystem>
#include <system_error>
#include <array>
#include <string.h>

#define COMPILER_FOO_CPP_ERR_MS_EXE
#define COMPILER_FOO_CPP

#include "C:\Users\okita\source\repos\CONTROL_public_header_create\public_header.h"

using namespace COMMON_DEFINE;

static constexpr std::wstring_view ERROR_CODE_TEXT_EN  =                             L"error code ";
static constexpr std::wstring_view DEFAULT_ALERT_MESSAGE_EN =                        L"System error occurred in EA 'control'";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_ONLY_EA_EN =                 L"Please do not run multiple instances of this Expert Advisor";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_EN =        L"Failed to create error log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_EN =          L"Failed to open error log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_EN =      L"Failed to create current log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_EN  =       L"Failed to open current log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_EN =           L"DLL not found or not enabled";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_EXIST_APP_EN  =              L"Application 'RuleDefender2.exe' not found";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_EN =         L"Failed to write error log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_EN =       L"Failed to write error log";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_TRADE_ALLOWED_EN =           L"Trade execution is not allowed";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_MT5_LANGUAGE_EN =            L"The language setting of MT5 is neither Japanese nor English";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_EN =       L"For trading time input, use '0' (single digit) for unset, or a 6-digit HHMMSS time";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_EN =       L"Enter trading time using digits only";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_EN =         L"Maximum trade count must be 10 or less";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_EN =         L"Next trade wait time must be between 0 and 10,800 seconds";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_EN =   L"Indicator value must be between 1 and 300";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_EN =   L"Please specify the loss percentage between 0.1 and 15.0";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_EN =        L"Fixed loss amount must be between 0.1 and 100,000.0";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_EN =     L"Commission (USD) must be between 0 and 1,000.0";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_EN =         L"GMT value must be between -23 and 23";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_EN =        L"For trading time input, use '0' (unset) or a 6-digit HHMMSS (HH=00?23, MM=00?59, SS=00?59)";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN = L"Trading time: '0' (unset → open1=close1, open2=close2) or HHMMSS (set both pairs)";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN =  L"Open and close must not cross 5:00 AM, and open must not extend beyond close";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_EN =      L"Failed to execute OnTimer event";
static constexpr std::wstring_view ERROR_MESSAGE_ERROR_LOG_DELETED_EN =              L"Error log has been deleted";
static constexpr std::wstring_view ERROR_MESSAGE_CURRENT_LOG_DELETED_EN =            L"Current log has been deleted";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_EN =       L"control watch is not running. Please review the settings";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_APP_BOOT_EN =                L"RuleDefender2 failed to start. Please verify the settings";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN =           L"Unauthorized modification of the sl file has been detected";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_CREATE_EN =          L"Failed to create sl file";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_OPEN_EN =            L"Failed to open sl file";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_EN =          L"Access to sl file failed";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_ERROR_NUM_FILE_EN =            L"Error status file not found";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_LANGUAGE_FILE_EN =             L"Language file not found";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_EN =    L"System error file not found";
static constexpr std::wstring_view ERROR_MESSAGE_UNKNOWN_ERROR_EN =                  L"An unknown error has occurred";
static constexpr std::wstring_view ERROR_MESSAGE_FRAUD_FILE_SIZE_EN =                L"Unauthorized modification of the file has been detected";

static constexpr std::wstring_view ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN =              L"Please reboot MT5";
static constexpr std::wstring_view ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN =          L"Continuing execution without logging";
static constexpr std::wstring_view ERROR_FOLLOWING_ALL_POSITION_CLOSED_EN =          L"All positions will be closed to protect the rules";

static constexpr std::wstring_view ERROR_CODE_TEXT_JP =                              L"エラーコード ";
static constexpr std::wstring_view DEFAULT_ALERT_MESSAGE_JP =                        L"EA名　CONTROLでシステムエラーが発生しました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_ONLY_EA_JP =                 L"このエキスパートアドバイザーを複数起動しないでください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_JP =        L"エラーログの作成に失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_JP =          L"エラーログを開けませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_JP =      L"カレントログの作成に失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_JP =        L"カレントログを開けませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_JP =           L"DLLが見つからないか有効化されていません";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_EXIST_APP_JP =               L"RuleDefender2.exe が見つかりませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_JP =         L"エラーログの書込みに失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_JP =       L"カレントログの書込みに失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_TRADE_ALLOWED_JP =           L"トレードが許可されない設定になっています";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_MT5_LANGUAGE_JP =            L"MT5の言語設定は英語、または日本語にしてください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_JP =       L"トレード時間の入力には指定なしの「0」か「HHMMSS」形式の6文字に限定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_JP =       L"トレード時間は全て数字のみで入力してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_JP =         L"最大トレード回数の値は10以下で入力してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_JP =         L"次回までのトレード待機秒数は0から10800の間で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_JP =   L"インジケーターの数値は1から300の間で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_JP =   L"損失金額の%指定は0.1から15.0までの間で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_JP =        L"損失金額の固定額は0.1から100000.0までの間で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_JP =     L"USD手数料は0から1000までの間で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_JP =         L"GMT時間の値は-23から23の範囲で指定してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_JP =        L"トレード時間はHHが00~23、MMとSSは00~59で入力するか、指定しない場合は0を1文字だけ入力してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_JP = L"トレード時間の設定(HHMMSS)、未設定(0を一文字だけ)はopen1とclose1、open2とclose2で共通にしてください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_JP =  L"トレード時間の設定はopenとcloseが日付変更時間のAM5:00を跨がず、またopenをcloseより遅くしないでください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_JP =      L"OnTimerイベントの呼び出しに失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_ERROR_LOG_DELETED_JP =              L"エラーログが削除されています";
static constexpr std::wstring_view ERROR_MESSAGE_CURRENT_LOG_DELETED_JP =            L"カレントログが削除されています";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_JP =       L"control watchが起動していません。設定を見直してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_APP_BOOT_JP =                L"RuleDefender2が起動できませんでした。設定を見直してください";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP =           L"SLファイルへの不正な改変が検出されました";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_CREATE_JP =          L"SLファイルを作成できませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_OPEN_JP =            L"SLファイルを開けませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_JP =          L"SLファイルへのアクセスに失敗しました";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_ERROR_NUM_FILE_JP =            L"エラーステータスファイルが見つかりませんでした";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_LANGUAGE_FILE_JP =             L"言語設定ファイルが見つかりません";
static constexpr std::wstring_view ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_JP =    L"システムエラーファイルが見つかりません";
static constexpr std::wstring_view ERROR_MESSAGE_UNKNOWN_ERROR_JP =                  L"不明なエラーが発生しました";
static constexpr std::wstring_view ERROR_MESSAGE_FRAUD_FILE_SIZE_JP =                L"ファイルへの不正な改変が検出されました";

static constexpr std::wstring_view ERROR_FOLLOWING_REBOOT_MT5_TEXT_JP =              L"MT5を再起動してください";
static constexpr std::wstring_view ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP =          L"ログの書き込みをせずに処理を続行します";
static constexpr std::wstring_view ERROR_FOLLOWING_ALL_POSITION_CLOSED_JP =          L"ルール保護のため全てのポジションをクローズします";

static constexpr std::wstring_view UNKNOWN_FAILED_NONE_GET_VALUE_EN =                L"A problem was detected, but the error code could not be retrieved";
static constexpr std::wstring_view UNKNOWN_FAILED_READ_FILE_EN =                     L"Failed to read error files";
static constexpr std::wstring_view UNKNOWN_FAILED_INITIALIZATION_FILE_EN =           L"Failed to initialize error files";
static constexpr std::wstring_view UNKNOWN_FAILED_INITIALIZATION_FILE_JP =           L"各設定ファイルの初期化に失敗しました";
static constexpr std::wstring_view FAILED_READ_FILES_NONE_EXIST_EN =                 L"Error files not found";
static constexpr std::wstring_view FAILED_READ_FILES_FRAUD_SIZE_EN =                 L"Unauthorized tampering with the error files has been detected";

static constexpr std::wstring_view FAILED_READ_FOLLOWING_CREATE_ERROR_FILES =        L"Run EA CONTROL in MT5 and create the error files";
static constexpr std::wstring_view FAILED_INITIALIZATION_FILE_EN =                   L"Please check the write permissions for the directory: ";
static constexpr std::wstring_view FAILED_INITIALIZATION_FILE_JP =                   L"以下の書き込み権限を確認してください";

class MESSAGE_DATA {

public:

    struct Message_Prototype {

        unsigned __int64 Error_Code;
        std::wstring_view Jp;
        std::wstring_view En;
        std::wstring_view Other;
    };

    struct Following_Prototype {

        unsigned __int64 Error_Code;
        std::wstring_view Jp;
        std::wstring_view En;
        std::wstring_view Other;
    };

    static constexpr Following_Prototype Folloeing_Table[] = {

        { CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_JP,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN},

        { CUSTOM_ERROR_CODE_FAILED_CREATE_ERROR_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_ERROR_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_CREATE_CURRENT_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_CURRENT_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_WRITE_ERROR_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_WRITE_CURRENT_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_ERROR_LOG_DELETED,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_CURRENT_LOG_DELETED,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},
    };
    
    static constexpr Message_Prototype Message_Table[] = {

        { CUSTOM_ERROR_CODE_NONE_ONLY_EA, 
         ERROR_MESSAGE_FAILED_ONLY_EA_JP,
         ERROR_MESSAGE_FAILED_ONLY_EA_EN,
         ERROR_MESSAGE_FAILED_ONLY_EA_EN},

        { CUSTOM_ERROR_CODE_NONE_DLL_EXIST,
         ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_JP,
         ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_EN,
         ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_EN},

        { CUSTOM_ERROR_CODE_NONE_TRADW_ALLOWED,
         ERROR_MESSAGE_FAILED_TRADE_ALLOWED_JP,
         ERROR_MESSAGE_FAILED_TRADE_ALLOWED_EN,
         ERROR_MESSAGE_FAILED_TRADE_ALLOWED_EN},

        { CUSTOM_ERROR_CODE_FAILED_LANGUAGE_SETING,
         ERROR_MESSAGE_FAILED_MT5_LANGUAGE_JP,
         ERROR_MESSAGE_FAILED_MT5_LANGUAGE_EN,
         ERROR_MESSAGE_FAILED_MT5_LANGUAGE_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_NONE_NUMBER,
         ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_LENGTH,
         ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_MAX_TRADE,
         ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_JP,
         ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_EN,
         ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_WAIT_TIME,
         ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_JP,
         ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_EN,
         ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_INDICATOR_VALUE,
         ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_JP,
         ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_EN,
         ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_PERCENTAGE_VALUE,
         ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_JP,
         ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_EN,
         ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_FIXID_VALUE,
         ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_JP,
         ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_EN,
         ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_COMMISION_USD_VALUE,
         ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_JP,
         ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_EN,
         ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_EN},

        { CUSTOM_ERROR_CODE_INPUT_FAILED_GMT_VALUE,
         ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_JP,
         ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_EN,
         ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_EN},

        { CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED,
         ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_JP,
         ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_EN,
         ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_EN},

        { CUSTOM_ERROR_CODE_INPUT_TIME_VALUE_FAILED,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_EN},

        { CUSTOM_ERROR_CODE_NONE_APP_EXIST,
         ERROR_MESSAGE_FAILED_APP_BOOT_JP,
         ERROR_MESSAGE_FAILED_APP_BOOT_EN,
         ERROR_MESSAGE_FAILED_APP_BOOT_EN},

        { CUSTOM_ERROR_CODE_NONE_WATCH_WINDOW,
         ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_JP,
         ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_EN,
         ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_EN},

        { CUSTOM_ERROR_CODE_FAILED_SL_FILE_SIZE,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN},

        { CUSTOM_ERROR_CODE_FRAUD_SL_FILE,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN},

        { CUSTOM_ERROR_CODE_FAILED_CREATE_ERROR_LOG,
         ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_JP,
         ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_EN,
         ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_ERROR_LOG,
         ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_JP,
         ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_EN,
         ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_CREATE_CURRENT_LOG,
         ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_JP,
         ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_EN,
         ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_OPEN_CURRENT_LOG,
         ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_JP,
         ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_EN,
         ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_WRITE_ERROR_LOG,
         ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_JP,
         ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_EN,
         ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_WRITE_CURRENT_LOG,
         ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_JP,
         ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_EN,
         ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_EN },

        { CUSTOM_ERROR_CODE_INPUT_TIME_SET_OR_UNSET_FAILED,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN },

        { CUSTOM_ERROR_CODE_INPUT_TIME_DATE_CHANGE_TIME_FAILED,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN },

        { CUSTOM_ERROR_CODE_ERROR_LOG_DELETED,
         ERROR_MESSAGE_ERROR_LOG_DELETED_JP,
         ERROR_MESSAGE_ERROR_LOG_DELETED_EN,
         ERROR_MESSAGE_ERROR_LOG_DELETED_EN },

        { CUSTOM_ERROR_CODE_CURRENT_LOG_DELETED,
         ERROR_MESSAGE_CURRENT_LOG_DELETED_JP,
         ERROR_MESSAGE_CURRENT_LOG_DELETED_EN,
         ERROR_MESSAGE_CURRENT_LOG_DELETED_EN },

        { CUSTOM_ERROR_CODE_FAILED_APP_BOOT,
         ERROR_MESSAGE_FAILED_APP_BOOT_JP,
         ERROR_MESSAGE_FAILED_APP_BOOT_EN,
         ERROR_MESSAGE_FAILED_APP_BOOT_EN },

        { CUSTOM_ERROR_CODE_FAILED_SL_FILE_CREATE,
         ERROR_MESSAGE_FAILED_SL_FILE_CREATE_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_CREATE_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_CREATE_EN },

        { CUSTOM_ERROR_CODE_FAILED_SL_FILE_OPEN,
         ERROR_MESSAGE_FAILED_SL_FILE_OPEN_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_OPEN_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_OPEN_EN },

        { CUSTOM_ERROR_CODE_FAILED_SL_FILE_ACCESS,
         ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_EN },

        { CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE,
         ERROR_MESSAGE_NONE_ERROR_NUM_FILE_JP,
         ERROR_MESSAGE_NONE_ERROR_NUM_FILE_EN,
         ERROR_MESSAGE_NONE_ERROR_NUM_FILE_EN },

        { CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE,
         ERROR_MESSAGE_NONE_LANGUAGE_FILE_JP,
         ERROR_MESSAGE_NONE_LANGUAGE_FILE_EN,
         ERROR_MESSAGE_NONE_LANGUAGE_FILE_EN },

        { CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE,
         ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_JP,
         ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_EN,
         ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_EN },

        { CUSTOM_ERROR_CODE_UNKNOWN_ERROR,
         ERROR_MESSAGE_UNKNOWN_ERROR_JP,
         ERROR_MESSAGE_UNKNOWN_ERROR_EN,
         ERROR_MESSAGE_UNKNOWN_ERROR_EN },

        { CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE,
         ERROR_MESSAGE_FRAUD_FILE_SIZE_JP,
         ERROR_MESSAGE_FRAUD_FILE_SIZE_EN,
         ERROR_MESSAGE_FRAUD_FILE_SIZE_EN }
    };
};

class MESSAGE_MANAGER {

private:

    static std::wstring_view GetMessage(const unsigned __int64& error_code, const MT5_LANGUAGE_NUMBER& language_value) {

        for (const MESSAGE_DATA::Message_Prototype& Prototype : MESSAGE_DATA::Message_Table) {

            if (Prototype.Error_Code == error_code) {

                if (language_value == JP)
                    return Prototype.Jp;

                else if (language_value == EN)
                    return Prototype.En;

                else if (language_value == OTHERS)
                    return Prototype.Other;
            }
        }

        return NULL_STRING;
    };

    static std::wstring_view GetFollowing(const unsigned __int64& error_code, const MT5_LANGUAGE_NUMBER& language_value) {

        for (const MESSAGE_DATA::Following_Prototype& Prototype : MESSAGE_DATA::Folloeing_Table) {

            if (Prototype.Error_Code == error_code) {

                if (language_value == JP)
                    return Prototype.Jp;

                else if (language_value == EN)
                    return Prototype.En;

                else if (language_value == OTHERS)
                    return Prototype.Other;
            }
        }

        return NULL_STRING;
    };

    static unsigned __int64 Restore_Error(const unsigned __int64& error_code) {

        return error_code + ERR_USER_ERROR_FIRST;
    }

    static std::wstring Create_Error_Num_Text(const bool& if_custom_error,const unsigned __int64& error_code) {

        if (if_custom_error) {

            return std::to_wstring(Restore_Error(error_code));
        }

        else {

            return std::to_wstring(error_code);
        }
    }

public:

    static std::wstring Assembly_Error_Text(
        
        const MT5_LANGUAGE_NUMBER&  language_value,
        const unsigned __int64&     error_code,
        const unsigned __int64&     visible_error,
        const std::wstring&         command_line,
              bool&                 if_custom_error) {

        std::wstring result = NULL_STRING;
        std::wstring Message = static_cast<std::wstring>(GetMessage(error_code, language_value));
        std::wstring Following = static_cast<std::wstring>(GetFollowing(error_code, language_value));

        unsigned __int64 Error_Code;

        if (visible_error != ERROR_SUCCESS) {

            Error_Code = visible_error;
            if_custom_error = false;
        }

        else {

            Error_Code = error_code;
        }
            

        if (language_value == JP) {

            result.append(DEFAULT_ALERT_MESSAGE_JP);
            result.append(LINE_BREAK);
            result.append(Message);
            result.append(LINE_BREAK);
            result.append(ERROR_CODE_TEXT_JP);
            result.append(Create_Error_Num_Text(if_custom_error,error_code));
            result.append(LINE_BREAK);
            result.append(command_line);
        }

        else if (language_value == EN || language_value == OTHERS) {

            result.append(DEFAULT_ALERT_MESSAGE_EN);
            result.append(LINE_BREAK);
            result.append(Message);
            result.append(LINE_BREAK);
            result.append(ERROR_CODE_TEXT_EN);
            result.append(Create_Error_Num_Text(if_custom_error, error_code));
            result.append(LINE_BREAK);
            result.append(command_line);
        }

        if (Following != NULL_STRING) {

            result.append(LINE_BREAK);
            result.append(Following);
        }

        return result;
    };

    static void Create_Message(const std::wstring& message) {

        MessageBox(NULL, message.c_str(), ERR_MS_WINDOW_TITLE.c_str(), MB_OK);
    };

    static std::wstring Unknown_Error_Message() {

        std::wstring Error_Text = NULL_STRING;

        Error_Text.append(DEFAULT_ALERT_MESSAGE_EN);
        Error_Text.append(LINE_BREAK);
        Error_Text.append(UNKNOWN_FAILED_NONE_GET_VALUE_EN);
        Error_Text.append(LINE_BREAK);
        Error_Text.append(ERROR_CODE_TEXT_EN);
        Error_Text.append(std::to_wstring(Restore_Error(CUSTOM_ERROR_CODE_UNKNOWN_ERROR)));

        return Error_Text;
    };
};

int WINAPI WinMain(

    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    FILE_MANAGER_USE File_Mng;
    FILETIME Curret_Time = {};

    GetSystemTimeAsFileTime(&Curret_Time);

    unsigned __int64 Boot_Time = ((unsigned __int64)Curret_Time.dwHighDateTime << 32) | Curret_Time.dwLowDateTime;

    if (File_Mng.Alignment_Checker() != ERROR_SUCCESS) {

        return 0;
    }

    else {

        HANDLE Mutex_Handle;

        if (!PROCESS_MANAGER::Trial_Get_Mutex(MUTEX_GLOBAL_NAME_ERROR_PROCESS, Mutex_Handle)) {

            return 0;
        }

        unsigned __int64 Error, Vis, Lang, Last_Write;
        bool If_Custom_Error;

        unsigned __int64 Error_Code = File_Mng.Read_Error(Error, Last_Write);

        if (Error_Code != ERROR_SUCCESS || Boot_Time < Last_Write) {

            return 0;
        }

        if (Error >= ERR_USER_ERROR_FIRST) {

            If_Custom_Error = true;
        }

        else {

            If_Custom_Error = false;
        }

        Error_Code = File_Mng.Read_Vis(Vis, Last_Write);

        if (Error_Code != ERROR_SUCCESS || Boot_Time < Last_Write) {

            return 0;
        }

        Error_Code = File_Mng.Read_Lang(Lang, Last_Write);

        if (Error_Code != ERROR_SUCCESS || Boot_Time < Last_Write) {

            return 0;
        }

        std::wstring Command_Line = NULL_STRING;

        Error_Code = PROCESS_MANAGER::To_Command_Line_Message(Command_Line);

        if (Error_Code != ERROR_SUCCESS) {

            return 0;
        }

        std::wstring Message_Text = MESSAGE_MANAGER::Assembly_Error_Text(static_cast<MT5_LANGUAGE_NUMBER>(Lang), Error, Vis, Command_Line, If_Custom_Error);

        MESSAGE_MANAGER::Create_Message(Message_Text);

        PROCESS_MANAGER::Close(Mutex_Handle);
    }

    return 0;
}