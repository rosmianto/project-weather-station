#include "Storage_Linux.h"

bool Storage_Linux::init() { return true; }

bool Storage_Linux::writeFile(std::string filename, std::string data) {
  char linuxPath[100] = "./";
  strcat(linuxPath, filename.c_str());
  FILE *fp = fopen(linuxPath, "w");
  if (fp == NULL) {
    return false;
  }
  auto writtenBytes = fprintf(fp, "%s", data.c_str());
  fclose(fp);

  return (writtenBytes == data.length());
}

std::string Storage_Linux::readFile(std::string filename) {
  char linuxPath[100] = "./";
  strcat(linuxPath, filename.c_str());
  FILE *fp = fopen(linuxPath, "r");
  if (fp == NULL) {
    return "";
  }
  char buffer[1000];
  auto readBytes = fread(buffer, 1, 1000, fp);
  fclose(fp);

  return std::string(buffer, readBytes);
}

bool Storage_Linux::deleteFile(std::string filename) {
  char linuxPath[100] = "./";
  strcat(linuxPath, filename.c_str());
  return (remove(linuxPath) == 0);
}

bool Storage_Linux::exists(std::string filename) {
  char linuxPath[100] = "./";
  strcat(linuxPath, filename.c_str());
  FILE *fp = fopen(linuxPath, "r");
  if (fp == NULL) {
    return false;
  }
  fclose(fp);
  return true;
}