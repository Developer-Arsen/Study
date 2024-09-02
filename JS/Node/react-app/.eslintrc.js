module.exports = {
    "env": {
      "browser": true,
      "node": true
    },
    "rules": {
      "no-undef": "off",
      "no-console": "off"
    },
    "overrides": [
      {
        "files": ["src/wasm/gaussian_blur.js"],
        "rules": {
          "no-undef": "off",
          "no-console": "off"
        }
      }
    ]
  };
  