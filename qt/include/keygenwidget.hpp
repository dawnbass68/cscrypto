#ifndef KEYGEN_WIDGET_HPP
#define KEYGEN_WIDGET_HPP

#include <QString>
#include <QWidget>

#include <common.hpp>

class QDialog;
class QFile;
class QLayout;
class QLineEdit;
class QListView;
class QMessageBox;
class QStatusBar;

namespace cscrypto {
namespace gui {

class KeyListModel;
class PasswordLineEdit;

class KeyGenWidget : public QWidget {
    Q_OBJECT

public:
    KeyGenWidget(QStatusBar& statusBar, KeyListModel* keysModel, QWidget* parent = nullptr);

signals:
    void enableKeyGen(bool);
    void enableNewSeed(bool);
    void enableKeysOperations(bool);

private:
    void tuneLayouts();
    void fillSeedLayout(QLayout*);
    void fillKeyLayout(QLayout*);
    void fillKeyListLayout(QLayout*);
    void fillMainLowLayout(QLayout*);

    void setupTypeSeedDia();
    void setSeedOnMsBox();
    void disableKeyGen();
    void setupEncDialog(QDialog*);
    void showPrivate();
    void activateKeysOps();

    void fillMasterSeedFromString(const QString&);
    void handleInputSeed();
    void handlePrivKeyLine();

    void saveSeedToFile();
    void loadSeedFromFile();
    void loadKeysFromFile();
    void decryptKeys();
    void dumpKeysToFile();
    void DumpKeysEncrypted();
    void DumpKeysClear();

    void genNewSeed();
    QString getSeedString();
    void genKeyPair();
    void genPublicFromPrivateDialog();

    QDialog* typeSeedDialog_;
    QMessageBox* seedMsBox_;
    QLineEdit* seedLineEdit_;
    QLineEdit* privateKeyLineEdit_;
    PasswordLineEdit* encryptionPswdLineEdit_;
    QStatusBar& statusBar_;

    cscrypto::keys_derivation::MasterSeed masterSeed_;
    cscrypto::keys_derivation::KeyId nextKeyId_;
    KeyListModel* keysModel_;
    QListView* keysListView_;
};
} // namespace gui
} // namespace cscrypto
#endif // KEYGEN_WIDGET_HPP
