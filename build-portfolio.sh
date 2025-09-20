#!/bin/bash

# Portfolio Build Script
# This script builds the complete portfolio including website and documentation

set -e  # Exit on any error

echo "🚀 Building Mathematical & Computational Sciences Portfolio..."

# Check if we're in the right directory
if [ ! -d "portfolio-website" ]; then
    echo "❌ Error: Please run this script from the repository root"
    exit 1
fi

# Final output directory
FINAL_DIR="docs"

# Clean previous builds
echo "🧹 Cleaning previous builds..."
rm -rf "$FINAL_DIR"
mkdir -p "$FINAL_DIR"

# Build the portfolio website
echo "📱 Building portfolio website..."
cd portfolio-website

# Check if node_modules exists, install if not
if [ ! -d "node_modules" ]; then
    echo "📦 Installing website dependencies..."
    npm install
fi

# Build the website
echo "🔨 Building website..."
npm run build

# Copy website to final directory
echo "📁 Copying website to final directory..."
cp -r dist/* "../$FINAL_DIR/"

cd ..
echo "✅ Portfolio website built successfully!"

# Build Quarto documentation if Quarto is available
if command -v quarto &> /dev/null; then
    echo "📚 Building Quarto documentation..."
    QUARTO_SOURCE_DIR="quarto-projects"
    QUARTO_OUTPUT_DIR_REL="$FINAL_DIR/quarto-projects"
    QUARTO_OUTPUT_DIR_ABS="$(pwd)/$QUARTO_OUTPUT_DIR_REL"
    
    mkdir -p "$QUARTO_OUTPUT_DIR_ABS"

    cd "$QUARTO_SOURCE_DIR"
    
    echo "  🔄 Rendering Euler methods analysis..."
    quarto render euler-methods-analysis.qmd --to html -o euler-methods-analysis.html
    mv euler-methods-analysis.html "$QUARTO_OUTPUT_DIR_ABS/"

    echo "  🔄 Rendering mathematical foundations..."
    quarto render mathematical-foundations.qmd --to html -o mathematical-foundations.html
    mv mathematical-foundations.html "$QUARTO_OUTPUT_DIR_ABS/"
    
    echo "✅ Quarto documentation built successfully!"
    cd ..
else
    echo "⚠️  Quarto not found - skipping documentation build"
    echo "   Install Quarto from https://quarto.org to build technical documentation"
fi

echo ""
echo "✅ Website build complete."
echo "   Your website is ready in the '$FINAL_DIR' directory."
echo "   Push this directory to your GitHub repository to publish on GitHub Pages."
echo ""
echo "🌐 To view the website locally, you can use a simple HTTP server:"
echo "   python3 -m http.server --directory $FINAL_DIR"
echo ""
echo "📤 Ready for deployment!"