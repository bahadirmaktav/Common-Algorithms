#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

int main() {
    auto logger = spdlog::stdout_color_st("main");   
    logger->set_level(spdlog::level::debug);
    logger->info("INFO TEST");
    logger->warn("WARN TEST");
}
