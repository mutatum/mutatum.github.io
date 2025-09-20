# Portfolio Customization Guide

This guide shows how to personalize your mathematical portfolio website.

## Quick Start

1. **Build the portfolio**:
   ```bash
   bash build-portfolio.sh
   ```

2. **Start development server**:
   ```bash
   cd portfolio-website && npm start
   ```

3. **View at**: http://localhost:3000

## Personal Information Updates

### 1. Name & Contact Info
Edit `portfolio-website/src/pug/index.pug`:

```pug
// Line ~53: Update name
h1.mb-0
    | Your 
    span.text-primary Name
// Change to:
h1.mb-0
    | [Your First Name] 
    span.text-primary [Your Last Name]

// Line ~59: Update contact
a(href='mailto:your.email@example.com') your.email@example.com
// Change to:
a(href='mailto:your.actual@email.com') your.actual@email.com
```

### 2. Social Media Links
Update social icons around line 67:

```pug
.social-icons
    a.social-icon(href='https://www.linkedin.com/in/yourprofile')
        i.fab.fa-linkedin-in
    a.social-icon(href='https://github.com/yourusername')
        i.fab.fa-github
    // Add more as needed
```

### 3. Profile Image
Replace `portfolio-website/src/assets/img/profile.jpg` with your photo.

## Content Customization

### Skills Adjustment
The skills already use the requested 0.X/1.0 format. To adjust competency levels:

```pug
// Example: C++ competency
.progress-bar.bg-primary(role='progressbar', style='width: 85%', aria-valuenow='85', aria-valuemin='0', aria-valuemax='100') 0.85/1.0
```

- `width: 85%` = visual bar width
- `aria-valuenow='85'` = accessibility value
- `0.85/1.0` = displayed text

### Adding Projects
Add new project entries in the projects section:

```pug
.d-flex.flex-column.flex-md-row.justify-content-between.mb-5
    .flex-grow-1
        h3.mb-0 Your Project Name
        .subheading.mb-3 Project Subtitle
        p Project description...
        p
            strong Technologies: 
            | List your tech stack
    .flex-shrink-0
        span.text-primary 2024
```

## Quarto Documentation

### Install Quarto
1. Download from https://quarto.org
2. Install following platform instructions

### Render Documents
```bash
cd quarto-projects
quarto render euler-methods-analysis.qmd
quarto render mathematical-foundations.qmd
```

### Customize Quarto Content
Edit the `.qmd` files to include your specific mathematical work:

- Add your research topics
- Include your code examples  
- Showcase your mathematical insights
- Add computational results

## Deployment

### GitHub Pages
1. Build: `npm run build` (from portfolio-website/)
2. Deploy `dist/` contents to gh-pages branch

### Netlify
1. Connect repository
2. Build command: `cd portfolio-website && npm run build`
3. Publish directory: `portfolio-website/dist`

## Mathematical Content

The portfolio already includes appropriate content for:
- École 42 Paris background ✓
- Licence Mathématiques générales ✓  
- MANU master program ✓
- Numerical methods expertise ✓
- Internship-seeking status ✓

Simply personalize the placeholder content with your actual information!

## Development Workflow

1. Edit content in `portfolio-website/src/pug/index.pug`
2. Website rebuilds automatically with `npm start`
3. Test changes at http://localhost:3000
4. Build for production with `npm run build`

The portfolio structure is professionally designed for mathematical/computational careers and ready for customization with your personal details.