cmake_minimum_required(VERSION 3.10)
project(LinuxFundamentals_C)

set(CMAKE_C_STANDARD 99)

# Thread library
find_package(Threads REQUIRED)

add_executable(fork_example src/process/fork_example.c)
add_executable(thread_example src/threads/thread_example.c)
target_link_libraries(thread_example Threads::Threads)

add_executable(signal_example src/signals/signal_example.c)

add_executable(pipe_example src/ipc/pipe_example.c)
add_executable(message_queue_example src/ipc/message_queue_example.c)
add_executable(shared_memory_example src/ipc/shared_memory_example.c)

add_executable(mutex_example src/sync/mutex_example.c)
target_link_libraries(mutex_example Threads::Threads)

add_executable(semaphore_example src/sync/semaphore_example.c)
target_link_libraries(semaphore_example Threads::Threads)

add_executable(producer_consumer src/sync/producer_consumer.c)
target_link_libraries(producer_consumer Threads::Threads)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Removing all build files"
)
