extern void delay_sec(unsigned int sec);
extern void delay_msec(unsigned int msec);


extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init();
extern void lcd_string(char *str);


extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *str);