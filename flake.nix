{
  description = "Learn raylib and compile with Nix";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in
      {
        devShells.default = pkgs.mkShell {
          # we do not need to add a comipler toolchain as one will always be
          # present `cc`
          # Why is it present? How can we use `gcc` or `clang` insted of
          # whatever default is provided
          packages = with pkgs; [
            raylib
            pkg-config
          ];
        };
      }
    );
}
