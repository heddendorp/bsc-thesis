# WebAssembly

## Structure

- Motivation
- History
- Features
- Running
- Structure
- Use for IoT

## Text

### WASM|Motivation

Beginning with static HTML pages the web has since developed into a very popular application paltform, accessible from a many different devices running different operating systems. JavaScript is the only natively supported language on the web. But even though it is universally used and made a lot of progress ion modern implementations it still has some problems as a compilation target. WebAssembly adresses these issues and provides a compilation target for the web.

### WASM|History

WebAssembly (WASM) was first announced in June 2015 and reached cross-browser consensus in March 2017. It's goal was to provide near native performance for browser based applications, which could only be written in JavaScript for a long time. Since being published in March 2017 it is currently usable for about 90% of global internet users. More recently the interested picked up around usage outside of the browser, which is also the main concern of thius thesis.

### WASM|Features

Being meant for the web, WASM has to achieve certain goals that give the platform very interesting properties. It has to be safe, since on the web, code is loaded mainly from untrusted sources. It has to be fast as the main motivation to introduce WebAssembly was to provide a compile target ont he web with reliable performance. Other than the usual low level code such as regular assembly, WebAssembly has to be protable and work in all the different circumstances the web is currently used. Lastly, because the code is transmitted over the notwork it has to be as small as possible to reduce bandwith and improve latency.

### WASM|Running

WASM is a low-level binary format, designed to be a portable target for high-level languages like C\C++ or Rust. It is executed on a stack-based virtual machine on which it exectutes in near-native speed due to it's low-level design. Still it runs in a memory-safe enviroinment inside the browser and is subject to the same security policies as JavaScipt code would be. WebAssembly modules are loaded with the application and provide bindings to JavaScript that make them usable in the browser.

### WASM|Structure

Together with the binary format of WebAssembly, there is a text format that defines a programming language with syntax and structure. Every WASM binary is a self contained module with functions, globals, tables, imports and exports. This concept provies both encapsulation and sandboxing since modules can only interact with their environment using imports and the client can only access the specified exports. Inside the module the code ins organized in functions, that can call each other even recursively.

### WASM|IoT

While WASM is developed for the web it carefully avoids any dependencies on the Web. It is meant to be an open standard that can be embedded ina variety of ways. The aforemanetioned goals, which WebAssembly achieves make it a very interesting format to explore on embedded devices. Due to it's aim to be universal it would allow the use of languages on MCUs that where not previously supported and since it is already meant to be transmitted over the network, also over the air updates of code running on the Controller are possible. To achieve portability the source level interface libraries would have to map the host environments capabilities either at build time or runtime.
