#ifndef ESCHER_SCROLLABLE_LAYOUT_VIEW_H
#define ESCHER_SCROLLABLE_LAYOUT_VIEW_H

#include <escher/glyphs_view.h>
#include <escher/layout_view.h>
#include <escher/scroll_view_data_source.h>
#include <escher/scrollable_view.h>

namespace Escher {

class ScrollableLayoutView : public ScrollableView<ScrollView::ArrowDecorator>,
                             public ScrollViewDataSource,
                             public CellWidget {
 public:
  ScrollableLayoutView(Responder* parentResponder, KDCoordinate leftRightMargin,
                       KDCoordinate topBottomMargin,
                       KDGlyph::Format format = {});
  ScrollableLayoutView(KDGlyph::Format format = {});
  Poincare::Layout layout() const override;
  KDFont::Size font() const { return m_expressionView.font(); }
  void setFont(KDFont::Size font) {
    m_expressionView.setFont(font);
    decorator()->setFont(font);
  }
  void setLayout(Poincare::Layout layout);
  void setTextColor(KDColor color) { m_expressionView.setTextColor(color); }
  void setBackgroundColor(KDColor backgroundColor) override;
  void setExpressionBackgroundColor(KDColor backgroundColor);

  // CellWidget
  const View* view() const override { return this; }
  Responder* responder() override { return this; }
  void defaultInitialization(CellWidget::Type type) override {
    m_expressionView.defaultInitialization(type);
  }
  void setHighlighted(bool highlighted) override;

 private:
  LayoutView m_expressionView;
};

}  // namespace Escher
#endif