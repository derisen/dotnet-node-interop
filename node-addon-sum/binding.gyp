{
  "variables": {
    "dll_files": [
      "lib/NativeLibrary.dll"
    ]
  },
  "targets": [
    {
      "target_name": "add",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/add.cpp",
        "./src/index.cpp"
      ],
      # "libraries": [
      #   "<(module_root_dir)/lib/NativeLibrary.lib",
      # ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "copies": [
        {
        "destination": "<(module_root_dir)/build/Release/",
            "files": [
                "<(module_root_dir)/lib/NativeLibrary.dll",
            ]
        },
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}