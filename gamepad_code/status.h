void updateHead(int headStatus){
  tft.setClipRect(8, 8, 64, 64);
  tft.drawRGBBitmap(8, 8, blox2_PIX[headStatus], 64, 64);
  tft.updateScreen();
}
