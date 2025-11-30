#!/usr/bin/env npx tsx

import { glob, readFile, writeFile } from "node:fs/promises";

const markdownFiles = (
  await Promise.all(
    (
      await Array.fromAsync(glob(["README.md", "documentation/**/*.md"]))
    ).map(async (path) => {
      return [path, await readFile(path, "utf8")];
    })
  )
).reduce((prev, [key, value]) => ({ ...prev, [key]: value }), {}) as {
  [key: string]: string;
};

const cppFiles = (
  await Promise.all(
    (
      await Array.fromAsync(glob("documentation/**/*.cpp"))
    ).map(async (path) => {
      return [path, await readFile(path, "utf8")];
    })
  )
).reduce((prev, [key, value]) => ({ ...prev, [key]: value }), {}) as {
  [key: string]: string;
};

for (let [markdownPath, markdownContents] of Object.entries(markdownFiles)) {
  for (const [cppPath, cppContents] of Object.entries(cppFiles)) {
    const pattern = new RegExp(`// ${cppPath}.+?([\`]{3})`, "ms");

    const matches = markdownContents.match(pattern);

    if (matches) {
      console.log(`Replacing code snippet in ${markdownPath} for ${cppPath}`);

      markdownContents = markdownContents.replace(
        pattern,
        `// ${cppPath}\n${cppContents.trim()}\n\`\`\``
      );

      await writeFile(markdownPath, markdownContents);
    }
  }
}
