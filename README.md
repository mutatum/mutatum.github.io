# Mutatum Resume & Portfolio

Site statique pour présenter le profil, le parcours et les projets numériques de Mutatum. Conçu pour GitHub Pages (`mutatum.github.io`) avec une attention particulière portée au design, à la lisibilité et à la mise en valeur de projets mathématiques et de programmation.

## ✨ Fonctionnalités

- **Page unique immersive** avec sections Profil, Formation, Expérience, Compétences, Projets et Intérêts.
- **Design premium** : fond dégradé, cartes en glassmorphisme, animations en douceur et typographie soignée (Manrope & Space Grotesk).
- **Mode clair/sombre** avec persistance de la préférence utilisateur.
- **Navigation responsive** : menu sticky, version mobile pliable, ancrages internes et retour en haut.
- **Section Projets prête** à recevoir visuels, extraits de code et liens externes.
- **Accessibilité renforcée** : structure sémantique, labels ARIA, focus states, texte bilingue.

## 📁 Structure

```
mutatum.github.io/
├── index.html          # Page principale
├── styles/
│   └── main.css        # Styles globaux, responsive & animations
├── scripts/
│   └── main.js         # Toggle du thème, menu mobile, effets d’apparition
└── README.md           # Ce document
```

## 🚀 Démarrage

### Prévisualiser en local

```bash
# Depuis le dossier du projet
default-browser index.html
```

Sur macOS/Linux, vous pouvez utiliser `open index.html` ou `xdg-open index.html`. Sous Windows (WSL), exécutez `wslview index.html` ou ouvrez le fichier directement dans l’explorateur.

### Déployer sur GitHub Pages

1. Poussez ce dépôt sur `main` avec le nom `mutatum.github.io`.
2. GitHub Pages servira automatiquement `index.html` à l’URL `https://mutatum.github.io`.

## 🛠️ Personnalisation

- **Projets** : remplacez chaque carte dans la section `#projets` par vos visuels (`<img>`), résumés ou snippets de code. Ajoutez ou dupliquez des cartes selon les besoins.
- **Couleurs & thèmes** : ajustez les variables CSS dans `:root` et `.light-theme` (`styles/main.css`).
- **Typographies** : modifiez les fontes Google importées dans `<head>`.
- **Animations** : adaptez la logique Intersection Observer (`scripts/main.js`) si vous souhaitez des effets différents.

## ✅ Qualité

- HTML5 valide, structuré pour le SEO (métadonnées, titres hiérarchisés, liens internes).
- Compatible desktop, tablette et mobile.
- Testé sans dépendances externes autres que Google Fonts.

## 📬 Contact

Le bouton “contact” et l’adresse `contact@mutatum.dev` dans la carte d’introduction peuvent être ajustés à vos coordonnées préférées.
