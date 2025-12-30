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

#define ERROR_CODE_TEXT_EN                              L"error code "
#define DEFAULT_ALERT_MESSAGE_EN                        L"System error occurred in EA 'control'"
#define ERROR_MESSAGE_FAILED_ONLY_EA_EN                 L"Please do not run multiple instances of this Expert Advisor"
#define ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_EN        L"Failed to create error log"
#define ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_EN          L"Failed to open error log"
#define ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_EN      L"Failed to create current log"
#define ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_EN        L"Failed to open current log"
#define ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_EN           L"DLL not found or not enabled"
#define ERROR_MESSAGE_FAILED_EXIST_APP_EN               L"Application 'RuleDefender2.exe' not found"
#define ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_EN         L"Failed to write error log"
#define ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_EN       L"Failed to write error log"
#define ERROR_MESSAGE_FAILED_TRADE_ALLOWED_EN           L"Trade execution is not allowed"
#define ERROR_MESSAGE_FAILED_MT5_LANGUAGE_EN            L"The language setting of MT5 is neither Japanese nor English"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_EN       L"For trading time input, use '0' (single digit) for unset, or a 6-digit HHMMSS time"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_EN       L"Enter trading time using digits only"
#define ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_EN         L"Maximum trade count must be 10 or less"
#define ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_EN         L"Next trade wait time must be between 0 and 10,800 seconds"
#define ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_EN   L"Indicator value must be between 1 and 300"
#define ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_EN   L"Please specify the loss percentage between 0.1 and 15.0"
#define ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_EN        L"Fixed loss amount must be between 0.1 and 100,000.0"
#define ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_EN     L"Commission (USD) must be between 0 and 1,000.0"
#define ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_EN         L"GMT value must be between -23 and 23"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_EN        L"For trading time input, use '0' (unset) or a 6-digit HHMMSS (HH=00?23, MM=00?59, SS=00?59)"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN L"Trading time: '0' (unset → open1=close1, open2=close2) or HHMMSS (set both pairs)"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN  L"Open and close must not cross 5:00 AM, and open must not extend beyond close"
#define ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_EN      L"Failed to execute OnTimer event"
#define ERROR_MESSAGE_ERROR_LOG_DELETED_EN              L"Error log has been deleted"
#define ERROR_MESSAGE_CURRENT_LOG_DELETED_EN            L"Current log has been deleted"
#define ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_EN       L"control watch is not running. Please review the settings"
#define ERROR_MESSAGE_FAILED_APP_BOOT_EN                L"RuleDefender2 failed to start. Please verify the settings"
#define ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN           L"Unauthorized modification of the sl file has been detected"
#define ERROR_MESSAGE_FAILED_SL_FILE_CREATE_EN          L"Failed to create sl file"
#define ERROR_MESSAGE_FAILED_SL_FILE_OPEN_EN            L"Failed to open sl file"
#define ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_EN          L"Access to sl file failed"
#define ERROR_MESSAGE_NONE_ERROR_NUM_FILE_EN            L"Error status file not found"
#define ERROR_MESSAGE_NONE_LANGUAGE_FILE_EN             L"Language file not found"
#define ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_EN    L"System error file not found"
#define ERROR_MESSAGE_UNKNOWN_ERROR_EN                  L"An unknown error has occurred"
#define ERROR_MESSAGE_FRAUD_FILE_SIZE_EN                L"Unauthorized modification of the file has been detected"

#define ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN              L"Please reboot MT5"
#define ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN          L"Continuing execution without logging"
#define ERROR_FOLLOWING_ALL_POSITION_CLOSED_EN          L"All positions will be closed to protect the rules"

#define ERROR_CODE_TEXT_JP                              L"エラーコード "
#define DEFAULT_ALERT_MESSAGE_JP                        L"EA名　CONTROLでシステムエラーが発生しました"
#define ERROR_MESSAGE_FAILED_ONLY_EA_JP                 L"このエキスパートアドバイザーを複数起動しないでください"
#define ERROR_MESSAGE_FAILED_CREATE_ERROR_LOG_JP        L"エラーログの作成に失敗しました"
#define ERROR_MESSAGE_FAILED_OPEN_ERROR_LOG_JP          L"エラーログを開けませんでした"
#define ERROR_MESSAGE_FAILED_CREATE_CURRENT_LOG_JP      L"カレントログの作成に失敗しました"
#define ERROR_MESSAGE_FAILED_OPEN_CURRENT_LOG_JP        L"カレントログを開けませんでした"
#define ERROR_MESSAGE_FAILED_EFFECTIVE_DLL_JP           L"DLLが見つからないか有効化されていません"
#define ERROR_MESSAGE_FAILED_EXIST_APP_JP               L"RuleDefender2.exe が見つかりませんでした"
#define ERROR_MESSAGE_FAILED_WRITE_ERROR_LOG_JP         L"エラーログの書込みに失敗しました"
#define ERROR_MESSAGE_FAILED_WRITE_CURRENT_LOG_JP       L"カレントログの書込みに失敗しました"
#define ERROR_MESSAGE_FAILED_TRADE_ALLOWED_JP           L"トレードが許可されない設定になっています"
#define ERROR_MESSAGE_FAILED_MT5_LANGUAGE_JP            L"MT5の言語設定は英語、または日本語にしてください"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_JP       L"トレード時間の入力には指定なしの「0」か「HHMMSS」形式の6文字に限定してください"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_JP       L"トレード時間は全て数字のみで入力してください"
#define ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_JP         L"最大トレード回数の値は10以下で入力してください"
#define ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_JP         L"次回までのトレード待機秒数は0から10800の間で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_JP   L"インジケーターの数値は1から300の間で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_JP   L"損失金額の%指定は0.1から15.0までの間で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_JP        L"損失金額の固定額は0.1から100000.0までの間で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_JP     L"USD手数料は0から1000までの間で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_JP         L"GMT時間の値は-23から23の範囲で指定してください"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_JP        L"トレード時間はHHが00~23、MMとSSは00~59で入力するか、指定しない場合は0を1文字だけ入力してください"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_JP L"トレード時間の設定(HHMMSS)、未設定(0を一文字だけ)はopen1とclose1、open2とclose2で共通にしてください"
#define ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_JP  L"トレード時間の設定はopenとcloseが日付変更時間のAM5:00を跨がず、またopenをcloseより遅くしないでください"
#define ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_JP      L"OnTimerイベントの呼び出しに失敗しました"
#define ERROR_MESSAGE_ERROR_LOG_DELETED_JP              L"エラーログが削除されています"
#define ERROR_MESSAGE_CURRENT_LOG_DELETED_JP            L"カレントログが削除されています"
#define ERROR_MESSAGE_FAILED_CONTROL_WATCH_RUN_JP       L"control watchが起動していません。設定を見直してください"
#define ERROR_MESSAGE_FAILED_APP_BOOT_JP                L"RuleDefender2が起動できませんでした。設定を見直してください"
#define ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP           L"SLファイルへの不正な改変が検出されました"
#define ERROR_MESSAGE_FAILED_SL_FILE_CREATE_JP          L"SLファイルを作成できませんでした"
#define ERROR_MESSAGE_FAILED_SL_FILE_OPEN_JP            L"SLファイルを開けませんでした"
#define ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_JP          L"SLファイルへのアクセスに失敗しました"
#define ERROR_MESSAGE_NONE_ERROR_NUM_FILE_JP            L"エラーステータスファイルが見つかりませんでした"
#define ERROR_MESSAGE_NONE_LANGUAGE_FILE_JP             L"言語設定ファイルが見つかりません"
#define ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_JP    L"システムエラーファイルが見つかりません"
#define ERROR_MESSAGE_UNKNOWN_ERROR_JP                  L"不明なエラーが発生しました"
#define ERROR_MESSAGE_FRAUD_FILE_SIZE_JP                L"ファイルへの不正な改変が検出されました"

#define ERROR_FOLLOWING_REBOOT_MT5_TEXT_JP              L"MT5を再起動してください"
#define ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP          L"ログの書き込みをせずに処理を続行します"
#define ERROR_FOLLOWING_ALL_POSITION_CLOSED_JP          L"ルール保護のため全てのポジションをクローズします"

#define UNKNOWN_FAILED_NONE_GET_VALUE_EN                L"A problem was detected, but the error code could not be retrieved"
#define UNKNOWN_FAILED_READ_FILE_EN                     L"Failed to read error files"
#define UNKNOWN_FAILED_INITIALIZATION_FILE_EN           L"Failed to initialize error files"
#define UNKNOWN_FAILED_INITIALIZATION_FILE_JP           L"各設定ファイルの初期化に失敗しました"
#define FAILED_READ_FILES_NONE_EXIST_EN                 L"Error files not found"
#define FAILED_READ_FILES_FRAUD_SIZE_EN                 L"Unauthorized tampering with the error files has been detected"

#define FAILED_READ_FOLLOWING_CREATE_ERROR_FILES        L"Run EA CONTROL in MT5 and create the error files"
#define FAILED_INITIALIZATION_FILE_EN                   L"Please check the write permissions for the directory: "
#define FAILED_INITIALIZATION_FILE_JP                   L"以下の書き込み権限を確認してください"

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

    static std::wstring_view GetMessage(const unsigned __int64 error_code, const MT5_LANGUAGE_NUMBER& language_value) {

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

    static std::wstring_view GetFollowing(const unsigned __int64 error_code, const MT5_LANGUAGE_NUMBER& language_value) {

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

    static bool              If_Visible_Message_Window() {

        HWND Handle = FindWindowW(ERR_MS_WINDOW_CLASS, ERR_MS_WINDOW_TITLE);

        if (Handle != NULL)
            return true;
        else
            return false;
    };

    static unsigned __int64 Restore_Error(unsigned __int64 error_code) {

        return error_code + ERR_USER_ERROR_FIRST;
    }

public:

    std::wstring Assembly_Error_Text(const MT5_LANGUAGE_NUMBER& language_value,
        unsigned __int64     error_code,
        const unsigned __int64& visible_error) {

        std::wstring result = NULL_STRING;
        std::wstring Message = static_cast<std::wstring>(GetMessage(error_code, language_value));
        std::wstring Following = static_cast<std::wstring>(GetFollowing(error_code, language_value));

        if (visible_error != ERROR_SUCCESS)
            error_code = visible_error;

        if (language_value == JP) {

            result.append(DEFAULT_ALERT_MESSAGE_JP);
            result.append(LINE_BREAK);
            result.append(Message);
            result.append(LINE_BREAK);
            result.append(ERROR_CODE_TEXT_JP);
            result.append(std::to_wstring(Restore_Error(error_code)));
        }

        else if (language_value == EN || language_value == OTHERS) {

            result.append(DEFAULT_ALERT_MESSAGE_EN);
            result.append(LINE_BREAK);
            result.append(Message);
            result.append(LINE_BREAK);
            result.append(ERROR_CODE_TEXT_EN);
            result.append(std::to_wstring(Restore_Error(error_code)));
        }

        if (Following != NULL_STRING) {

            result.append(LINE_BREAK);
            result.append(Following);
        }

        return result;
    };

    void Create_Message(std::wstring message) {

        if (!If_Visible_Message_Window()) {

            MessageBox(NULL, message.c_str(), ERR_MS_WINDOW_TITLE, MB_OK);
        }
    };

    void Unknown_Error_Message() {

        if (!If_Visible_Message_Window()) {

            std::wstring Error_Text = NULL_STRING;

            Error_Text.append(DEFAULT_ALERT_MESSAGE_EN);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(UNKNOWN_FAILED_NONE_GET_VALUE_EN);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(ERROR_CODE_TEXT_EN);
            Error_Text.append(std::to_wstring(Restore_Error(CUSTOM_ERROR_CODE_UNKNOWN_ERROR)));

            MessageBox(NULL, Error_Text.c_str(), ERR_MS_WINDOW_TITLE, MB_OK);
        }
    };

    void File_Read_Error_Message(const unsigned __int64& error_code) {

        std::wstring Error_Text = NULL_STRING;

        Error_Text.append(DEFAULT_ALERT_MESSAGE_EN);
        Error_Text.append(LINE_BREAK);
        Error_Text.append(UNKNOWN_FAILED_READ_FILE_EN);
        Error_Text.append(LINE_BREAK);
        Error_Text.append(ERROR_CODE_TEXT_EN);
        Error_Text.append(std::to_wstring(error_code));

        if (error_code > ERR_USER_ERROR_FIRST) {

            Error_Text.append(LINE_BREAK);

            if (error_code - ERR_USER_ERROR_FIRST == CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE ||
                error_code - ERR_USER_ERROR_FIRST == CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE ||
                error_code - ERR_USER_ERROR_FIRST == CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE) {

                Error_Text.append(FAILED_READ_FILES_NONE_EXIST_EN);
                Error_Text.append(LINE_BREAK);
                Error_Text.append(FAILED_READ_FOLLOWING_CREATE_ERROR_FILES);
            }

            else if (error_code - ERR_USER_ERROR_FIRST == CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE) {

                Error_Text.append(FAILED_READ_FILES_FRAUD_SIZE_EN);
            }
        }

        MessageBox(NULL, Error_Text.c_str(), ERR_MS_WINDOW_TITLE, MB_OK);
    };

    void File_Write_Error_Message(const unsigned __int64& error_code, const MT5_LANGUAGE_NUMBER& language_value,const std::wstring& path) {

        std::wstring Error_Text = NULL_STRING;

        if (language_value == JP) {

            Error_Text.append(DEFAULT_ALERT_MESSAGE_JP);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(UNKNOWN_FAILED_INITIALIZATION_FILE_JP);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(ERROR_CODE_TEXT_JP);
            Error_Text.append(std::to_wstring(error_code));
            Error_Text.append(LINE_BREAK);
            Error_Text.append(path);
            Error_Text.append(CONTROL_FOLDER_DRC);
            Error_Text.append(FAILED_INITIALIZATION_FILE_JP);
        }

        else if (language_value == EN || language_value == OTHERS) {

            Error_Text.append(DEFAULT_ALERT_MESSAGE_EN);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(UNKNOWN_FAILED_INITIALIZATION_FILE_EN);
            Error_Text.append(LINE_BREAK);
            Error_Text.append(ERROR_CODE_TEXT_EN);
            Error_Text.append(std::to_wstring(error_code));
            Error_Text.append(LINE_BREAK);
            Error_Text.append(FAILED_INITIALIZATION_FILE_EN);
            Error_Text.append(path);
            Error_Text.append(CONTROL_FOLDER_DRC);
        }

        MessageBox(NULL, Error_Text.c_str(), ERR_MS_WINDOW_TITLE, MB_OK);
    }
};

class FILE_TYPE {

public:

    enum class TYPE_NUMBER : size_t {

        Error,
        Language,
        Visible,
        Max
    };

private:

    static constexpr std::array<std::wstring_view, static_cast<size_t>(TYPE_NUMBER::Max)> FileNames = {
        
        ERR_MS_ERR_NUM_FULL_PATH,
        MT5_LANGUAGE_NUM_FULL_PATH,
        ERR_MS_VISIBLE_ERR_NUM_FULL_PATH
    };

    static constexpr std::array<size_t, static_cast<size_t>(TYPE_NUMBER::Max)> FileSizes = {

        ERR_MS_ERR_NUM_FILE_SIZE,
        MT5_LANGUAGE_NUM_FILE_SIZE,
        ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE
    };

    static constexpr std::array<size_t, static_cast<size_t>(TYPE_NUMBER::Max)> ErrorCode = {

       CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE,
       CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE,
       CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE
    };

    static constexpr std::wstring_view ToFileName(TYPE_NUMBER type) {

        return FileNames[static_cast<size_t>(type)];
    };

    static constexpr size_t ToFileSize(TYPE_NUMBER type) {

        return FileSizes[static_cast<size_t>(type)];
    };

    static constexpr size_t ToErrorCode(TYPE_NUMBER type) {

        return ErrorCode[static_cast<size_t>(type)];
    };

public:

    static const size_t Get_File_Size(const size_t count) {

        return ToFileSize(static_cast<FILE_TYPE::TYPE_NUMBER>(count));
    }

    static const std::wstring Get_File_Name(const size_t count) {

        return std::wstring(ToFileName(static_cast<FILE_TYPE::TYPE_NUMBER>(count)));
    }

    static const size_t Get_Error_Code(const size_t count) {

        return ToErrorCode(static_cast<FILE_TYPE::TYPE_NUMBER>(count));
    }
};

class FILE_DATA {

private:

    std::wstring      Name;
    HANDLE            Handle = 0;
    size_t            Size = 0;
    std::vector<char> Read_Date;

public:

    FILE_DATA() = default;

    ~FILE_DATA() { Close(); }

    void Initialization(size_t                file_size,
                        size_t                file_date_size,
                        const    std::wstring file_name) {

        Name = file_name;
        Handle = INVALID_HANDLE_VALUE;
        Size = file_size;
        Read_Date.assign(file_date_size, 0);
    }

    void Close() {

        if (Handle != INVALID_HANDLE_VALUE) {
            
            CloseHandle(Handle);
            Handle = INVALID_HANDLE_VALUE;
        } 
        
        std::vector<char>().swap(Read_Date);
    }

    void Set_Handle(HANDLE handle) {

        Handle = handle;
    }

    char* Set_Read_Date() {

        return Read_Date.data();
    }

    HANDLE Get_Handle() const {

        return Handle;
    }

    std::wstring Get_Name() const {

        return Name;
    }

    size_t Get_Size() const {

        return Size;
    }

    char* Get_Read_Date() {

        return Read_Date.data();
    }
};

class FILE_MANAGER {

private:

    std::vector<FILE_DATA> Data;

public:

    void Initialization() {

        Data.resize(static_cast<size_t>(FILE_TYPE::TYPE_NUMBER::Max));

        for (size_t i = 0; i < static_cast<size_t>(FILE_TYPE::TYPE_NUMBER::Max); i++) {

            Data[i].Initialization(FILE_TYPE::Get_File_Size(i), FILE_TYPE::Get_File_Size(i), FILE_TYPE::Get_File_Name(i));
        }
    }

    void Close() {

        for (size_t i = 0; i < static_cast<size_t>(FILE_TYPE::TYPE_NUMBER::Max); i++) {

            Data[i].Close();
        }
    }

    const size_t Keep_Error_Value_Close(const size_t error_code) {

        Close();

        return error_code;
    }

    size_t File_Read_Safety_Check(std::wstring drc) {

        std::wstring FullPath;
        std::error_code err;
        HANDLE Handle;

        for (size_t i = 0; i < static_cast<size_t>(FILE_TYPE::TYPE_NUMBER::Max); i++) {

            FullPath = drc + Data[i].Get_Name();

            if (!std::filesystem::exists(FullPath, err)) {
                
                return Keep_Error_Value_Close(FILE_TYPE::Get_Error_Code(i) + ERR_USER_ERROR_FIRST);
            }

            else {

                SetLastError(ERROR_SUCCESS);

                Handle = CreateFileW(

                    FullPath.c_str(),
                    GENERIC_READ | GENERIC_WRITE,
                    FILE_SHARE_READ | FILE_SHARE_WRITE,
                    NULL,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);

                if (Handle == INVALID_HANDLE_VALUE) {

                    return Keep_Error_Value_Close(GetLastError());
                }

                else {

                    Data[i].Set_Handle(Handle);

                    LARGE_INTEGER File_Size;

                    if (!GetFileSizeEx(Data[i].Get_Handle(), &File_Size)) {

                        return Keep_Error_Value_Close(GetLastError());
                    }

                    else if (File_Size.QuadPart != Data[i].Get_Size()) {

                        return Keep_Error_Value_Close(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE + ERR_USER_ERROR_FIRST);
                    }

                    else {

                        DWORD Get_File_Byte;

                        if (!ReadFile(

                            Data[i].Get_Handle(),
                            Data[i].Set_Read_Date(),
                            static_cast<DWORD>(Data[i].Get_Size()),
                            &Get_File_Byte,
                            NULL)) {

                            return Keep_Error_Value_Close(GetLastError());
                        }

                        else if (Get_File_Byte != Data[i].Get_Size()) {

                            return Keep_Error_Value_Close(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE + ERR_USER_ERROR_FIRST);
                        }
                    }
                }
            }
        }

        return ERROR_SUCCESS;
    };

    bool Get_Read_Data(const FILE_TYPE::TYPE_NUMBER& data_type, unsigned __int64& result) {

        errno_t If_Success = memcpy_s(

            &result,
            sizeof(result),
            Data[static_cast<size_t>(data_type)].Get_Read_Date(),
            Data[static_cast<size_t>(data_type)].Get_Size());

        if (If_Success == ERROR_SUCCESS) {

            return true;
        }

        else
            return false;
    };

    unsigned __int64 Reset_File_Value() {

        for (size_t i = 0; i < static_cast<size_t>(FILE_TYPE::TYPE_NUMBER::Max); i++) {

            std::memset(Data[i].Get_Read_Date(), 0, Data[i].Get_Size());

            LARGE_INTEGER liDistanceToMove;
            liDistanceToMove.QuadPart = 0;
            if (!SetFilePointerEx(Data[i].Get_Handle(), liDistanceToMove, NULL, FILE_BEGIN)) {
                return Keep_Error_Value_Close(GetLastError());
            }

            else {

                DWORD Get_File_Byte;

                SetLastError(ERROR_SUCCESS);

                if (!WriteFile(

                    Data[i].Get_Handle(),
                    Data[static_cast<size_t>(i)].Get_Read_Date(),
                    static_cast<DWORD>(Data[i].Get_Size()),
                    &Get_File_Byte,
                    NULL)) {

                    if (ERROR_IO_PENDING != GetLastError())
                        return Keep_Error_Value_Close(GetLastError());
                }

                if (!SetEndOfFile(Data[i].Get_Handle()))
                    return Keep_Error_Value_Close(GetLastError());
            }
        }

        return ERROR_SUCCESS;
    };
};

int WINAPI WinMain(

    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    ///////////////////////////////////////////////////////////
    //
    // 各種ファイルの親ディレクトリを取得
    //

    PWSTR path = nullptr;
    
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path))) {

        std::wstring localAppData(path);
        CoTaskMemFree(path);

        MESSAGE_MANAGER Message;
        FILE_MANAGER File;

        File.Initialization();

        size_t Error_Code = File.File_Read_Safety_Check(localAppData);

        if (Error_Code != ERROR_SUCCESS) {

            Message.File_Read_Error_Message(Error_Code);
        }

        else {

            unsigned __int64 Lang;
            unsigned __int64 Error;
            unsigned __int64 Visible;

            if (File.Get_Read_Data(FILE_TYPE::TYPE_NUMBER::Language, Lang) &&
                File.Get_Read_Data(FILE_TYPE::TYPE_NUMBER::Error, Error) &&
                File.Get_Read_Data(FILE_TYPE::TYPE_NUMBER::Visible, Visible)) {

                if (OTHERS < static_cast<MT5_LANGUAGE_NUMBER>(Lang) ||
                    CUSTOM_ERROR_CODE_MAX_VALUE <= Error) {

                    Message.Unknown_Error_Message();
                }

                else {

                    if (Error > ERR_USER_ERROR_FIRST) {

                        Error -= ERR_USER_ERROR_FIRST;
                    }

                    Message.Create_Message(Message.Assembly_Error_Text(static_cast<MT5_LANGUAGE_NUMBER>(Lang), Error, Visible));

                    unsigned __int64 Error_Code = File.Reset_File_Value();

                    if (Error_Code != ERROR_SUCCESS) {

                        Message.File_Write_Error_Message(Error_Code, static_cast<MT5_LANGUAGE_NUMBER>(Lang), localAppData);
                    }
                }
            }

            else {

                Message.Unknown_Error_Message();
            }
        }

        File.Close();
    }

    return 0;
}