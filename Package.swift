// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "vorbis",
    platforms: [
        .macOS(.v10_13),
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "vorbis",
            targets: ["vorbis"]),
    ],
    targets: [
        .binaryTarget(
            name: "vorbis",
            url: "https://github.com/de4me/vorbis-xcode/releases/download/v1.3.7.2/vorbis.zip",
            checksum: "6cb749f3d4f5288c7edfd0d7e998150d7eb02ac6fefe0d145cd54f33e1d43bf2"
        ),
    ]
)
