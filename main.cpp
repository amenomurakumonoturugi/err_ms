
#include "common_mqh_cpp_PCH.h"

constexpr std::wstring_view ERROR_CODE_TEXT_EN  =                             L"error code ";
constexpr std::wstring_view DEFAULT_ALERT_MESSAGE_EN =                        L"System error occurred in EA 'control'";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_ONLY_EA_EN =                 L"Please do not run multiple instances of this Expert Advisor";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_LOG_EN =              L"Failed to create error log";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_LOG_EN =                L"Failed to open error log";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_LOG_EN =               L"Failed to write error log";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_TRADE_ALLOWED_EN =           L"Trade execution is not allowed";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_MT5_LANGUAGE_EN =            L"The language setting of MT5 is neither Japanese nor English";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_EN =       L"For trading time input, use '0' (single digit) for unset, or a 6-digit HHMMSS time";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_EN =       L"Enter trading time using digits only";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_EN =         L"Maximum trade count must be 10 or less";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_EN =         L"Next trade wait time must be between 0 and 10,800 seconds";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_EN =   L"Indicator value must be between 1 and 300";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_EN =   L"Please specify the loss percentage between 0.1 and 15.0";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_EN =        L"Fixed loss amount must be between 0.1 and 100,000.0";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_EN =     L"Commission (USD) must be between 0 and 1,000.0";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_EN =         L"GMT value must be between -23 and 23";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_EN =        L"For trading time input, use '0' (unset) or a 6-digit HHMMSS (HH=00?23, MM=00?59, SS=00?59)";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN = L"Trading time: '0' (unset → open1=close1, open2=close2) or HHMMSS (set both pairs)";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN =  L"Open and close must not cross 5:00 AM, and open must not extend beyond close";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_EN =      L"Failed to execute OnTimer event";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_LOG_DELETED_EN =             L"Failed to optimize log file size";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_APP_BOOT_EN =                L"Interlinking program failed to start. Please verify the settings";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN =           L"Unauthorized modification of the sl file has been detected";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_CREATE_EN =          L"Failed to create sl file";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_OPEN_EN =            L"Failed to open sl file";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_EN =          L"Access to sl file failed";
constexpr std::wstring_view ERROR_MESSAGE_NONE_ERROR_NUM_FILE_EN =            L"Error status file not found";
constexpr std::wstring_view ERROR_MESSAGE_NONE_LANGUAGE_FILE_EN =             L"Language file not found";
constexpr std::wstring_view ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_EN =    L"System error file not found";
constexpr std::wstring_view ERROR_MESSAGE_UNKNOWN_ERROR_EN =                  L"An unknown error has occurred";
constexpr std::wstring_view ERROR_MESSAGE_FRAUD_FILE_SIZE_EN =                L"Unauthorized modification of the file has been detected";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_FILE_OPERATION_EN =          L"Failed to read or write file";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_OBJECT_EN =                  L"Failed to operate object";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_POSITION_DATA_EN =       L"Position data retrieval failed";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_POSITION_COMMISSION_EN = L"Position commission retrieval failed";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_CALC_PRICE_EN =          L"Calculated price retrieval failed";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_POSITION_CLOSE_EN =          L"Failed to close position";

constexpr std::wstring_view ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN =              L"Please reboot MT5";
constexpr std::wstring_view ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN =          L"Continuing execution without logging";
constexpr std::wstring_view ERROR_FOLLOWING_ALL_POSITION_CLOSED_EN =          L"All positions will be closed to protect the rules";
constexpr std::wstring_view ERROR_FOLLOWING_BUG_POSSIBILITY_EN =              L"It may not operate correctly";

constexpr std::wstring_view ERROR_CODE_TEXT_JP =                              L"エラーコード ";
constexpr std::wstring_view DEFAULT_ALERT_MESSAGE_JP =                        L"EA名　CONTROLでシステムエラーが発生しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_ONLY_EA_JP =                 L"このエキスパートアドバイザーを複数起動しないでください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_CREATE_LOG_JP =              L"エラーログの作成に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_OPEN_LOG_JP =                L"エラーログを開けませんでした";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_WRITE_LOG_JP =               L"エラーログの書込みに失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_TRADE_ALLOWED_JP =           L"トレードが許可されない設定になっています";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_MT5_LANGUAGE_JP =            L"MT5の言語設定は英語、または日本語にしてください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_LENGTH_JP =       L"トレード時間の入力には指定なしの「0」か「HHMMSS」形式の6文字に限定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_NUMBER_JP =       L"トレード時間は全て数字のみで入力してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_MAX_TRADE_JP =         L"最大トレード回数の値は10以下で入力してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_WAIT_TIME_JP =         L"次回までのトレード待機秒数は0から10800の間で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_INDICATOR_VALUE_JP =   L"インジケーターの数値は1から300の間で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_PERCENTAGE_LOSS_JP =   L"損失金額の%指定は0.1から15.0までの間で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_FIXID_LOSS_JP =        L"損失金額の固定額は0.1から100000.0までの間で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_COMMISION_USD_JP =     L"USD手数料は0から1000までの間で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_GMT_VALUE_JP =         L"GMT時間の値は-23から23の範囲で指定してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SCOPE_JP =        L"トレード時間はHHが00~23、MMとSSは00~59で入力するか、指定しない場合は0を1文字だけ入力してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_JP = L"トレード時間の設定(HHMMSS)、未設定(0を一文字だけ)はopen1とclose1、open2とclose2で共通にしてください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_JP =  L"トレード時間の設定はopenとcloseが日付変更時間のAM5:00を跨がず、またopenをcloseより遅くしないでください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_ON_TIMER_SUCCESSED_JP =      L"OnTimerイベントの呼び出しに失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_LOG_DELETED_JP =             L"ログのファイルサイズ適正化に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_APP_BOOT_JP =                L"連携プログラムが起動できませんでした。設定を見直してください";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP =           L"SLファイルへの不正な改変が検出されました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_CREATE_JP =          L"SLファイルを作成できませんでした";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_OPEN_JP =            L"SLファイルを開けませんでした";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_SL_FILE_ACCESS_JP =          L"SLファイルへのアクセスに失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_NONE_ERROR_NUM_FILE_JP =            L"エラーステータスファイルが見つかりませんでした";
constexpr std::wstring_view ERROR_MESSAGE_NONE_LANGUAGE_FILE_JP =             L"言語設定ファイルが見つかりません";
constexpr std::wstring_view ERROR_MESSAGE_NONE_VISIBLE_ERROR_NUM_FILE_JP =    L"システムエラーファイルが見つかりません";
constexpr std::wstring_view ERROR_MESSAGE_UNKNOWN_ERROR_JP =                  L"不明なエラーが発生しました";
constexpr std::wstring_view ERROR_MESSAGE_FRAUD_FILE_SIZE_JP =                L"ファイルへの不正な改変が検出されました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_FILE_OPERATION_JP =          L"ファイルの書込み、または読み込みに失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_OBJECT_JP =                  L"オブジェクトの操作に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_POSITION_DATA_JP =       L"ポジションデータの取得に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_POSITION_COMMISSION_JP = L"ポジション手数料の取得に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_GET_CALC_PRICE_JP =          L"計算価格の取得に失敗しました";
constexpr std::wstring_view ERROR_MESSAGE_FAILED_POSITION_CLOSE_JP =          L"ポジションの決済に失敗しました";



constexpr std::wstring_view ERROR_FOLLOWING_REBOOT_MT5_TEXT_JP =              L"MT5を再起動してください";
constexpr std::wstring_view ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP =          L"ログの書き込みをせずに処理を続行します";
constexpr std::wstring_view ERROR_FOLLOWING_ALL_POSITION_CLOSED_JP =          L"ルール保護のため全てのポジションをクローズします";
constexpr std::wstring_view ERROR_FOLLOWING_BUG_POSSIBILITY_JP =              L"正常に動作しない可能性があります";

constexpr std::wstring_view UNKNOWN_FAILED_NONE_GET_VALUE_EN =                L"A problem was detected, but the error code could not be retrieved";
constexpr std::wstring_view UNKNOWN_FAILED_READ_FILE_EN =                     L"Failed to read error files";
constexpr std::wstring_view UNKNOWN_FAILED_INITIALIZATION_FILE_EN =           L"Failed to initialize error files";
constexpr std::wstring_view UNKNOWN_FAILED_INITIALIZATION_FILE_JP =           L"各設定ファイルの初期化に失敗しました";
constexpr std::wstring_view FAILED_READ_FILES_NONE_EXIST_EN =                 L"Error files not found";
constexpr std::wstring_view FAILED_READ_FILES_FRAUD_SIZE_EN =                 L"Unauthorized tampering with the error files has been detected";

constexpr std::wstring_view FAILED_READ_FOLLOWING_CREATE_ERROR_FILES =        L"Run EA CONTROL in MT5 and create the error files";
constexpr std::wstring_view FAILED_INITIALIZATION_FILE_EN =                   L"Please check the write permissions for the directory: ";
constexpr std::wstring_view FAILED_INITIALIZATION_FILE_JP =                   L"以下の書き込み権限を確認してください";

class MESSAGE_DATA {

public:

    struct Message_Prototype {

        ulong Error_Code;
        std::wstring_view Jp;
        std::wstring_view En;
        std::wstring_view Other;
    };

    struct Following_Prototype {

        ulong Error_Code;
        std::wstring_view Jp;
        std::wstring_view En;
        std::wstring_view Other;
    };

    static constexpr Following_Prototype Folloeing_Table[] = {

        { CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_JP,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN,
         ERROR_FOLLOWING_REBOOT_MT5_TEXT_EN},

        { CUSTOM_ERROR_CODE_FAILED_CREATE_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_WRITE_LOG,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_LOG_DELETED,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_JP,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN,
         ERROR_FOLLOWING_NONE_LOG_WRITE_MODE_EN},

        { CUSTOM_ERROR_CODE_FAILED_GET_DRC,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_FILE,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_LOCK,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_ROOT_DRC,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_LOCK_ONE,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_INIT,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_WRITE,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_GET_FILE_SIZE,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_POINTER_SET,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},

        { CUSTOM_ERROR_CODE_FAILED_FILE_READ,
         ERROR_FOLLOWING_BUG_POSSIBILITY_JP,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN,
         ERROR_FOLLOWING_BUG_POSSIBILITY_EN},
    };
    
    static constexpr Message_Prototype Message_Table[] = {

        { CUSTOM_ERROR_CODE_NONE_ONLY_EA, 
         ERROR_MESSAGE_FAILED_ONLY_EA_JP,
         ERROR_MESSAGE_FAILED_ONLY_EA_EN,
         ERROR_MESSAGE_FAILED_ONLY_EA_EN},

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

        { CUSTOM_ERROR_CODE_FRAUD_SL_FILE,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_JP,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN,
         ERROR_MESSAGE_FAILED_SL_FILE_FRAUD_EN},

        { CUSTOM_ERROR_CODE_FAILED_CREATE_LOG,
         ERROR_MESSAGE_FAILED_CREATE_LOG_JP,
         ERROR_MESSAGE_FAILED_CREATE_LOG_EN,
         ERROR_MESSAGE_FAILED_CREATE_LOG_EN},

        { CUSTOM_ERROR_CODE_FAILED_OPEN_LOG,
         ERROR_MESSAGE_FAILED_OPEN_LOG_JP,
         ERROR_MESSAGE_FAILED_OPEN_LOG_EN,
         ERROR_MESSAGE_FAILED_OPEN_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_WRITE_LOG,
         ERROR_MESSAGE_FAILED_WRITE_LOG_JP,
         ERROR_MESSAGE_FAILED_WRITE_LOG_EN,
         ERROR_MESSAGE_FAILED_WRITE_LOG_EN },

        { CUSTOM_ERROR_CODE_INPUT_TIME_SET_OR_UNSET_FAILED,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_SET_OR_UNSET_EN },

        { CUSTOM_ERROR_CODE_INPUT_TIME_DATE_CHANGE_TIME_FAILED,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_JP,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN,
         ERROR_MESSAGE_FAILED_INPUT_TIME_DATE_CHANGE_EN },

        { CUSTOM_ERROR_CODE_FAILED_LOG_DELETED,
         ERROR_MESSAGE_FAILED_LOG_DELETED_JP,
         ERROR_MESSAGE_FAILED_LOG_DELETED_EN,
         ERROR_MESSAGE_FAILED_LOG_DELETED_EN },

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
         ERROR_MESSAGE_FRAUD_FILE_SIZE_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_DRC,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_OPEN_FILE,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_LOCK,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_LOG_NONE_GET_UNKNOWN_TIME,
         ERROR_MESSAGE_FAILED_WRITE_LOG_JP,
         ERROR_MESSAGE_FAILED_WRITE_LOG_EN,
         ERROR_MESSAGE_FAILED_WRITE_LOG_EN },

        { CUSTOM_ERROR_CODE_FAILED_ROOT_DRC,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_LOCK_ONE,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_OBJECT,
         ERROR_MESSAGE_FAILED_OBJECT_JP,
         ERROR_MESSAGE_FAILED_OBJECT_EN,
         ERROR_MESSAGE_FAILED_OBJECT_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_INIT,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_WRITE,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_FILE_SIZE,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_POINTER_SET,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_FILE_READ,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_JP,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN,
         ERROR_MESSAGE_FAILED_FILE_OPERATION_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_POSITION_DATA,
         ERROR_MESSAGE_FAILED_GET_POSITION_DATA_JP,
         ERROR_MESSAGE_FAILED_GET_POSITION_DATA_EN,
         ERROR_MESSAGE_FAILED_GET_POSITION_DATA_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_POSITION_COMMISSION,
         ERROR_MESSAGE_FAILED_GET_POSITION_COMMISSION_JP,
         ERROR_MESSAGE_FAILED_GET_POSITION_COMMISSION_EN,
         ERROR_MESSAGE_FAILED_GET_POSITION_COMMISSION_EN },

        { CUSTOM_ERROR_CODE_FAILED_GET_CALC_PRICE,
         ERROR_MESSAGE_FAILED_GET_CALC_PRICE_JP,
         ERROR_MESSAGE_FAILED_GET_CALC_PRICE_EN,
         ERROR_MESSAGE_FAILED_GET_CALC_PRICE_EN },

        { CUSTOM_ERROR_CODE_FAILED_POSITION_CLOSE,
         ERROR_MESSAGE_FAILED_POSITION_CLOSE_JP,
         ERROR_MESSAGE_FAILED_POSITION_CLOSE_EN,
         ERROR_MESSAGE_FAILED_POSITION_CLOSE_EN },

        { CUSTOM_ERROR_CODE_FAILED_APP_EXIST,
          ERROR_MESSAGE_FAILED_APP_BOOT_JP,
          ERROR_MESSAGE_FAILED_APP_BOOT_EN,
          ERROR_MESSAGE_FAILED_APP_BOOT_EN },
    };
};

class MESSAGE_MANAGER {

private:

    string Get_Message(const ulong& error, const ulong& lang) {

        for (const MESSAGE_DATA::Message_Prototype& Prototype : MESSAGE_DATA::Message_Table) {

            ulong Primary_Value;

            if (GET_PRIMARY_ERROR_CODE(error, Primary_Value) != ERROR_SUCCESS)
                return NULL_STRING;

            if (Prototype.Error_Code == Primary_Value) {

                if (lang == JP)
                    return Prototype.Jp.data();

                else if (lang == EN)
                    return Prototype.En.data();

                else if (lang == OTHERS)
                    return Prototype.Other.data();
            }
        }

        return NULL_STRING;
    };

    string Get_Following(const ulong& error, const ulong& lang) {

        for (const MESSAGE_DATA::Following_Prototype& Prototype : MESSAGE_DATA::Folloeing_Table) {

            ulong Primary_Value;

            if (GET_PRIMARY_ERROR_CODE(error, Primary_Value) != ERROR_SUCCESS)
                return NULL_STRING;

            if (Prototype.Error_Code == Primary_Value) {

                if (lang == JP)
                    return Prototype.Jp.data();

                else if (lang == EN)
                    return Prototype.En.data();

                else if (lang == OTHERS)
                    return Prototype.Other.data();
            }
        }

        return NULL_STRING;
    };

public:

    string Create_Error_Text(
        
        const ulong&     lang,
        const ulong&     error,
        const ulong&     visible,
        _vector<string>& command_line) {

        string result = NULL_STRING;
        string Message = Get_Message(error, lang);
        string Following = Get_Following(error, lang);
        std::wstring Error_Text = std::to_wstring(visible);

        if (lang == JP) {

            result.append(DEFAULT_ALERT_MESSAGE_JP.data());
            result.append(L"\r\n");
            result.append(Message);
            result.append(L"\r\n");

            if (Following != NULL_STRING) {

                result.append(Following);
                result.append(L"\r\n");
            }

            result.append(ERROR_CODE_TEXT_JP.data());
        }

        else if (lang == EN || lang == OTHERS) {

            result.append(DEFAULT_ALERT_MESSAGE_EN.data());
            result.append(L"\r\n");
            result.append(Message);
            result.append(L"\r\n");

            if (Following != NULL_STRING) {

                result.append(Following);
                result.append(L"\r\n");
            }

            result.append(ERROR_CODE_TEXT_EN.data());
        }

        result.append(Error_Text.data());
        result.append(L"\r\n");

        for (int i = 0; i < COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL; i++) {

            if (i != COMMAND_LINE_ASSIGNMENT_NUMBER_EXE_APP_NAME) {

                result.append(command_line.Get_At(i));
                result.append(SPACE_STRING);
            }
        }   

        result.append(L"\r\n");

        return result;
    };

    void Create_Message(const string& message,HWND& handle) {

        if (!handle)
            return;

        int Text_End = GetWindowTextLengthW(handle);

        SendMessageW(handle, EM_SETSEL, Text_End, Text_End);

        string Text = message;
        Text.append(L"\r\n");

        SendMessageW(handle, EM_REPLACESEL, FALSE, (LPARAM)Text.data());
    };

    void Post_Error_Message(const string& message) {

        HWND Window_Handle = nullptr;

        for (int i = 0; i < TRY_FIND_COUNTER; ++i) {

            string Class_Name = ERR_MS_WINDOW_CLASS();
            string Window_Name = ERR_MS_WINDOW_TITLE();

            Window_Handle = FindWindowW(Class_Name, Window_Name);

            if (Window_Handle)
                break;

            Sleep(SLEEP_MILLI_SECOND_VALUE);
        }

        if (Window_Handle) {

            COPYDATASTRUCT cds = {};

            cds.dwData = 1;
            cds.cbData = (DWORD)(message.size() + 1) * sizeof(wchar_t);
            cds.lpData = (PVOID)message.data();

            SendMessageW(Window_Handle, WM_COPYDATA, 0, (LPARAM)&cds);
        }
    }
};

class COMPOSITION_ERR_FLOW : public FLOW_FILE_CONTROLLER {

public:

    inline ulong Create_Error_Message(const ulong& boot_time, MESSAGE_MANAGER& message_mng, PROCESS_MANAGER& process_mng, string& result) {

        BYTE8_FILE_MANAGER File_Mng;

        ulong Error = 0, Vis = 0, Lang = 0, Last_Time = 0;

        ulong Error_Code = Byte8_Read(Error, Last_Time, ITEM_ERR_MS_ERR_FILE_NAME(), File_Mng);

        if (Error_Code != ERROR_SUCCESS)
            return Error_Code;

        File_Mng.Lock_Mng.Unlock_File(File_Mng.File_Handle.get());

        if (boot_time < Last_Time) {

            SYSTEM_ERROR_VALUE::Set_System_Error(

                CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME),
                _GetWin32LastError(),
                __LINE__,
                __FILEW__
            );

            return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME);
        }

        Error_Code = Byte8_Read(Vis, Last_Time, ITEM_ERR_MS_VISIBLE_ERR_NUM_FILE_NAME(), File_Mng);

        if (Error_Code != ERROR_SUCCESS)
            return Error_Code;

        File_Mng.Lock_Mng.Unlock_File(File_Mng.File_Handle.get());

        if (boot_time < Last_Time) {

            SYSTEM_ERROR_VALUE::Set_System_Error(

                CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME),
                _GetWin32LastError(),
                __LINE__,
                __FILEW__
            );

            return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME);
        }

        Error_Code = Byte8_Read(Lang, Last_Time, ITEM_LANGUAGE_FILE_NAME(), File_Mng);

        if (Error_Code != ERROR_SUCCESS)
            return Error_Code;

        File_Mng.Lock_Mng.Unlock_File(File_Mng.File_Handle.get());

        if (boot_time < Last_Time) {

            SYSTEM_ERROR_VALUE::Set_System_Error(

                CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME),
                _GetWin32LastError(),
                __LINE__,
                __FILEW__
            );

            return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME);
        }

        _vector<string> Command_Line;

        Error_Code = process_mng.Get_Command_Line(Command_Line);

        if (Error_Code != ERROR_SUCCESS)
            return Error_Code;

        result = message_mng.Create_Error_Text(Lang, Error, Vis, Command_Line);

        return ERROR_SUCCESS;
    }
};

HWND g_hEdit = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg) {

    case WM_CREATE: {
        
        g_hEdit = CreateWindowExW(

            0,
            L"EDIT",
            nullptr,
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
            0,
            0,
            0,
            0,
            hwnd,
            nullptr,
            (HINSTANCE)GetWindowLongPtrW(hwnd, GWLP_HINSTANCE),
            nullptr);

        HFONT hFont = CreateFontW(
            
            16,
            0,
            0,
            0,
            FW_NORMAL,
            FALSE,
            FALSE,
            FALSE,
            DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            FIXED_PITCH | FF_MODERN,
            L"Consolas");

        SendMessageW(g_hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

        return 0;
    }


    case WM_COPYDATA: {

        PCOPYDATASTRUCT pCDS = reinterpret_cast<PCOPYDATASTRUCT>(lParam);

        if (pCDS && pCDS->dwData == 1) {

            const wchar_t* pErrorMsg = reinterpret_cast<const wchar_t*>(pCDS->lpData);

            if (pErrorMsg) {

                MESSAGE_MANAGER Message_Mng;

                Message_Mng.Create_Message(pErrorMsg, g_hEdit);
            }
        }

        return TRUE;
    }

    case WM_SIZE: {
        
        MoveWindow(g_hEdit, 0, 0, LOWORD(lParam), HIWORD(lParam), TRUE);

        return 0;
    }

    case WM_DESTROY: {

        PostQuitMessage(0);

        return 0;
    }

    }

    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(

    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    FILETIME Curret_Time = {};

    GetSystemTimeAsFileTime(&Curret_Time);

    ulong Boot_Time = ((ulong)Curret_Time.dwHighDateTime << 32) | Curret_Time.dwLowDateTime;

    PROCESS_MANAGER Process_Mng;

    string Text;

    MESSAGE_MANAGER Message_Mng;
    COMPOSITION_ERR_FLOW Err_Flow;

    ulong Error_Code = Err_Flow.Create_Error_Message(Boot_Time, Message_Mng, Process_Mng, Text);

    if (Error_Code != ERROR_SUCCESS)
        return 0;

    if (!Process_Mng.Trial_Get_Mutex(MUTEX_LOCAL_NAME_SYSTEM_LOG_PROCESS())) {

        Message_Mng.Post_Error_Message(Text);

        return 0;
    }

    WNDCLASSEXW wc = { sizeof(WNDCLASSEXW) };

    string Class_Name = ERR_MS_WINDOW_CLASS();
    string Window_Name = ERR_MS_WINDOW_TITLE();

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = Class_Name;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    if (!RegisterClassExW(&wc))
        return 0;

    HWND hwndMain = CreateWindowExW(

        WS_EX_CLIENTEDGE,
        Class_Name,
        Window_Name,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        550,
        400,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

    if (!hwndMain)
        return 0;
    
    ShowWindow(hwndMain, nCmdShow);
    UpdateWindow(hwndMain);

    Message_Mng.Create_Message(Text, g_hEdit);

    MSG msg;

    while (GetMessageW(&msg, nullptr, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return (int)msg.wParam;
}